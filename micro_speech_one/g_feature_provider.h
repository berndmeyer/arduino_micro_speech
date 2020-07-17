#ifndef _G_FEATURE_PROVIDER_H
#define _G_FEATURE_PROVIDER_H

/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <TensorFlowLite.h>
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"

// kTfLiteError
// kTfLiteOk

// Binds itself to an area of memory intended to hold the input features for an
// audio-recognition neural network model, and fills that data area with the
// features representing the current audio input, for example from a microphone.
// The audio features themselves are a two-dimensional array, made up of
// horizontal slices representing the frequencies at one point in time, stacked
// on top of each other to form a spectrogram showing how those frequencies
// changed over time.
class FeatureProvider {
 public:
  // Create the provider, and bind it to an area of memory. This memory should
  // remain accessible for the lifetime of the provider object, since subsequent
  // calls will fill it with feature data. The provider does no memory
  // management of this data.
  FeatureProvider(tflite::ErrorReporter* error_reporter,
      int feature_size, int8_t* feature_data);
  ~FeatureProvider();

  // Fills the feature data with information from audio inputs, and returns how
  // many feature slices were updated.
  TfLiteStatus RequestFeature();

  // Acquires a Feature, once the feature is available.
  TfLiteStatus RetrieveFeature();

  // Checks whether the feature is ready to collect
  bool IsFeatureReady();

  bool IsFeatureRequested();

  void DisplayFeature();
 private:
  tflite::ErrorReporter* error_reporter_;
  int feature_size_;
  int8_t* feature_data_;
  bool feature_requested_;
  // Make sure we don't try to use cached information if this is the first call
  // into the provider.
  bool is_first_run_;
};

#endif  // _G_FEATURE_PROVIDER_H
