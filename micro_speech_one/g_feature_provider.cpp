#include "g_feature_provider.h"
#include "g_audio_provider.h"
#include "micro_features_micro_features_generator.h"
#include "micro_features_micro_model_settings.h"

FeatureProvider::FeatureProvider(tflite::ErrorReporter* error_reporter, 
    int feature_size, 
    int8_t* feature_data)
    : error_reporter_(error_reporter),
      feature_size_(feature_size),
      feature_data_(feature_data),
      is_first_run_(true),
      feature_requested_(false) {

  // Initialize the feature data to default values.
  for (int n = 0; n < feature_size_; ++n) {
    feature_data_[n] = 0;
  }

  InitRecording(error_reporter_);
}

FeatureProvider::~FeatureProvider() {}

TfLiteStatus FeatureProvider::RequestFeature() {
  TF_LITE_REPORT_ERROR(error_reporter_, "Feature requested..");
  
  if (feature_requested_) {
    TF_LITE_REPORT_ERROR(error_reporter_, "Feature requested already");
    return kTfLiteOk;
  }

  if (!IsRecording()) {
    TF_LITE_REPORT_ERROR(error_reporter_, "Feature not recording");
    StartRecording(error_reporter_);
    feature_requested_ = true;
  }

  TF_LITE_REPORT_ERROR(error_reporter_, "Feature recording");
  
  return kTfLiteOk;
}

TfLiteStatus FeatureProvider::RetrieveFeature() {
  TF_LITE_REPORT_ERROR(error_reporter_, "Feature Retrieved");

   //  DisplayAudio(error_reporter_);

  for (int new_slice = 0; new_slice < kFeatureSliceCount;  ++new_slice) {

    // Calculate the location to store the Feature Data
    int8_t* new_slice_data = feature_data_ + (new_slice * kFeatureSliceSize);
    size_t num_samples_read;

    // Calculate the step
    int16_t* audio_samples = nullptr;
    int audio_samples_size = 0;

    //const int new_step = (current_step - kFeatureSliceCount + 1) + new_slice;
    const int32_t slice_start_ms = (new_slice * kFeatureSliceStrideMs);
    
    TfLiteStatus audio_status = RetrieveAudio(error_reporter_, 
        (slice_start_ms > 0 ? slice_start_ms : 0),
        kFeatureSliceDurationMs,
        &audio_samples_size,
        &audio_samples);

    if (audio_status != kTfLiteOk) {
      TF_LITE_REPORT_ERROR(error_reporter_,
        "Retrieve Audio failed");

      return audio_status;
    }
    
    if (audio_samples_size < kMaxAudioSampleSize) {
      TF_LITE_REPORT_ERROR(error_reporter_,
        "Audio data size %d too small, want %d",
        audio_samples_size, kMaxAudioSampleSize);

      return kTfLiteError;
    }

    if (is_first_run_) {
      TfLiteStatus init_status = InitializeMicroFeatures(error_reporter_);
      if (init_status != kTfLiteOk) {
        return init_status;
      }
      is_first_run_ = false;
    }
    
    TfLiteStatus generate_status = GenerateMicroFeatures(
        error_reporter_, audio_samples, audio_samples_size, kFeatureSliceSize,
        new_slice_data, &num_samples_read);

    if (generate_status != kTfLiteOk) {
      TF_LITE_REPORT_ERROR(error_reporter_,
        "Retrieve Audio failed");

      return generate_status;
    }
  }


  TF_LITE_REPORT_ERROR(error_reporter_,
        "Retrieved feature");
  
  feature_requested_ = false;
  return kTfLiteOk;
}

bool FeatureProvider::IsFeatureReady() {
  bool is_ready = IsRecordingReady();
  return is_ready;
}

bool FeatureProvider::IsFeatureRequested() {
  return feature_requested_;
}

void FeatureProvider::DisplayFeature() {
  
  for (int i = 0; i < kFeatureSliceCount; i++) {
    for (int j = 0; j < kFeatureSliceSize; j++) {
      
      int8_t t = feature_data_[(i * kFeatureSliceCount) + j];
      
      TF_LITE_REPORT_ERROR(error_reporter_, "%d %d %d", i, j, t);
      
    }
  }

  DisplayAudio(error_reporter_);
}
