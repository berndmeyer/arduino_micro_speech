#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "micro_features_micro_model_settings.h"
#include "g_audio_provider.h"
#include "PDM.h"

namespace {

// Location to catch all audio samples, on interrupt callback
constexpr int kAudioBufferSize = DEFAULT_PDM_BUFFER_SIZE / 2;
int16_t g_audio_buffer[kAudioBufferSize];

// An internal buffer able to fit 32x our sample size
constexpr int kAudioCaptureBufferSize = DEFAULT_PDM_BUFFER_SIZE * 32;
int16_t g_audio_capture_buffer[kAudioCaptureBufferSize];
bool g_is_recording = false;
volatile int16_t g_recording_offset = 0;
volatile int32_t g_recording_start_timestamp = 0;

// Mark as volatile so we can check in a while loop to see if
// any samples have arrived yet.
volatile int32_t g_latest_audio_timestamp = 0;
bool g_is_audio_initialized = false;

tflite::ErrorReporter* error_reporter_ = nullptr;

}

void OnRecordingStart() {
    digitalWrite(LED_BUILTIN, HIGH);
    g_is_recording = true;
    g_recording_start_timestamp = g_latest_audio_timestamp;
    g_recording_offset = 0;
}

void OnRecordingStop() {
    digitalWrite(LED_BUILTIN, LOW);
    g_is_recording = false;
}

// This is the interrupt callback routine, when the PDF buffer is full
void OnPDMReady() {
  // This is how many bytes of new data we have each time this is called
  const int number_of_samples = DEFAULT_PDM_BUFFER_SIZE;
  
  // Calculate what timestamp the last audio sample represents
  const int32_t time_in_ms =
      g_latest_audio_timestamp +
      (number_of_samples / (kAudioSampleFrequency / 1000));

  // Check whether to store or dump the audio samples
  if (g_is_recording) {
    
    // Read the data to the correct place in our buffer
    PDM.read(g_audio_capture_buffer + g_recording_offset, DEFAULT_PDM_BUFFER_SIZE);
    
    // PDM.read(g_audio_buffer, DEFAULT_PDM_BUFFER_SIZE);

    g_recording_offset += kAudioBufferSize;
    if (g_recording_offset >= kAudioCaptureBufferSize) {
        OnRecordingStop();
    }
  } else {
    // Read the data to the correct place in our buffer
    PDM.read(g_audio_buffer, DEFAULT_PDM_BUFFER_SIZE);
  }
  
  // This is how we let the outside world know that new audio data has arrived.
  g_latest_audio_timestamp = time_in_ms;
}

TfLiteStatus InitRecording(tflite::ErrorReporter* error_reporter) {
  error_reporter_ = error_reporter;
  
  TfLiteStatus init_status = kTfLiteError;
  if (!g_is_audio_initialized) {

    TF_LITE_REPORT_ERROR(error_reporter, "Recording initializing");

    // Hook up the callback that will be called with each sample
    PDM.onReceive(OnPDMReady);
    // Start listening for audio: MONO @ 16KHz with gain at 20
    PDM.begin(1, kAudioSampleFrequency);
    PDM.setGain(0x50);
    // Block until we have our first audio sample
    while (!g_latest_audio_timestamp) {
    }
    
    g_is_audio_initialized = true;
  } 
  
  TF_LITE_REPORT_ERROR(error_reporter, "Recording initialized");
  return kTfLiteOk;
}

// Initiates a recording of the PDM microphone into a provided buffer
TfLiteStatus StartRecording(tflite::ErrorReporter* error_reporter) { 
  TfLiteStatus init_status = InitRecording(error_reporter);
  
  if (init_status != kTfLiteOk) {
    TF_LITE_REPORT_ERROR(error_reporter, "Recording failed");
    return init_status;
  }

  if (g_is_recording) {
    TF_LITE_REPORT_ERROR(error_reporter, "Recording already");
    return kTfLiteOk;
  }

  for (int i = 0; i < kAudioCaptureBufferSize; i++) {
    g_audio_capture_buffer[i] = 0;
  }

  OnRecordingStart();
  TF_LITE_REPORT_ERROR(error_reporter_, "Recording started");
  return kTfLiteOk;
}

// Flag to check whether recording is occurring
bool IsRecording() {
  return g_is_recording;
}

// Flag to indicate if the available buffer is ready for collection
bool IsRecordingReady() {
//  TF_LITE_REPORT_ERROR(error_reporter_, "Recording @ %d", g_recording_offset);
  return g_recording_offset >= kAudioCaptureBufferSize;
}

int32_t LatestAudioTimestamp() {
  return g_latest_audio_timestamp;
}

TfLiteStatus RetrieveAudio(tflite::ErrorReporter* error_reporter,
    int start_ms,
    int duration_ms,
    int* audio_samples_size,
    int16_t** audio_samples) {
      
//  TF_LITE_REPORT_ERROR(error_reporter_, "Retrieving audio @ %d", start_ms);

  const int start_offset = start_ms * (kAudioSampleFrequency / 1000);
  const int duration_sample_count = duration_ms * (kAudioSampleFrequency / 1000);

  if (start_offset + duration_sample_count < kAudioCaptureBufferSize) {
    *audio_samples = &g_audio_capture_buffer[start_offset];
    *audio_samples_size = kMaxAudioSampleSize;

    return kTfLiteOk;
  }

  return kTfLiteError;
}

void DisplayAudio(tflite::ErrorReporter* error_reporter) {
  for (int i = 0; i < kAudioCaptureBufferSize; i++) {
    TF_LITE_REPORT_ERROR(error_reporter_, "Audio %d @ %d", i,  g_audio_capture_buffer[i]);
  }
}
