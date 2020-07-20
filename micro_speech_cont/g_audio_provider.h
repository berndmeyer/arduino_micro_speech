#ifndef _G_AUDIO_PROVIDER_H
#define _G_AUDIO_PROVIDER_H

#include <TensorFlowLite.h>
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"

// Initiates the PDM microphone
TfLiteStatus InitRecording(tflite::ErrorReporter* error_reporter);

// Initiates a recording of the PDM microphone into a provided buffer
TfLiteStatus StartRecording(tflite::ErrorReporter* error_reporter);

// Used to validate if the Audio Provider is currently recording
bool IsRecording();

// Flag to indicate if the available buffer is ready for collection
bool IsRecordingReady();

// Audio timestamp as calculate from the latest audio sampling
int32_t LatestAudioTimestamp();

// Using the current idle audio buffer, check for noises which exceed the current threshold
bool DetectNoise(tflite::ErrorReporter* error_reporter);

TfLiteStatus RetrieveAudio(tflite::ErrorReporter* error_reporter,
    int start_ms,
    int duration_ms,
    int* audio_sample_size,
    int16_t** audio_samples);

void DisplayAudio(tflite::ErrorReporter* error_reporter);
    
#endif
