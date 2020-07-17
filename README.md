# arduino_micro_speech
A SB-CNN implementation of the Arduino micro_speech project

There are two implementations of the TensorFlow micro_speech example project in this repository.

## Executive summary

SB-CNN is a model which has been [shown](https://creativecommons.org/licenses/by-nc/3.0/au/) to achieve good recognition when used on small microcontrollers.  

As the full SB-CNN model is too large (400K+ parameters) to reside in the SRAM of a Nano 33 BLE Sense microcontroller (256KB), this implementation a SB-CNN lite model is used instead.  Using a simple Yes No training set, the model has been trained using 303 audio samples to get a 100% accuracy. (split into training 80%, validation 10% and testing 10%).  A full SB-CNN model typically utilizes a 128 x 128 input tensor and 5x5 convolution size, whereas this SB-CNN light model uses a 49 x 40 input tensor and 3x3 convolution size.

Using the Nano 33 BLE Sense running the model, I have been able to achieve ~79% accuracy when using the micro_speech_one sketch in this repository.  Accuracy on in the micro_speech_cont project folder is not as high, and is currently under review.

```
Actual,  Prediction,  Count, Percent
Yes,     Yes,         152,   0.7916666666666666
Yes,     No,          40,    0.20833333333333334
No,      No,          149,   0.7925531914893617
No,      Yes,         39,    0.2074468085106383
```

## SB-CNN (49 x 40)

```
Model: "sequential"
_________________________________________________________________
Layer (type)                 Output Shape              Param #   
=================================================================
conv2d (Conv2D)              (None, 49, 40, 24)        240       
_________________________________________________________________
batch_normalization (BatchNo (None, 49, 40, 24)        96        
_________________________________________________________________
max_pooling2d (MaxPooling2D) (None, 12, 20, 24)        0         
_________________________________________________________________
activation (Activation)      (None, 12, 20, 24)        0         
_________________________________________________________________
conv2d_1 (Conv2D)            (None, 12, 20, 48)        10416     
_________________________________________________________________
batch_normalization_1 (Batch (None, 12, 20, 48)        192       
_________________________________________________________________
max_pooling2d_1 (MaxPooling2 (None, 3, 10, 48)         0         
_________________________________________________________________
activation_1 (Activation)    (None, 3, 10, 48)         0         
_________________________________________________________________
conv2d_2 (Conv2D)            (None, 1, 8, 48)          20784     
_________________________________________________________________
batch_normalization_2 (Batch (None, 1, 8, 48)          192       
_________________________________________________________________
activation_2 (Activation)    (None, 1, 8, 48)          0         
_________________________________________________________________
flatten (Flatten)            (None, 384)               0         
_________________________________________________________________
dropout (Dropout)            (None, 384)               0         
_________________________________________________________________
dense (Dense)                (None, 64)                24640     
_________________________________________________________________
activation_3 (Activation)    (None, 64)                0         
_________________________________________________________________
dropout_1 (Dropout)          (None, 64)                0         
_________________________________________________________________
dense_1 (Dense)              (None, 2)                 130       
_________________________________________________________________
activation_4 (Activation)    (None, 2)                 0         
=================================================================
Total params: 56,690
Trainable params: 56,450
Non-trainable params: 240
_________________________________________________________________
```

## micro_speech_cont

A continuous inference sketch, using SB-CNN, in the same tradition as the source micro_speech example project.

## micro_speech_one

A one-shot inference sketch, using a SB-CNN (49x40) model, as a variant to the source micro_speech example project.

There is a button attached to P1_11, with a pull-up resistor, so that when the button is pressed, the pin is connected to ground, and the signal is brought LOW.  The PDM microphone then acquires 16000 samples of audio (32*512), before running inference, and dumping the result to serial. 

## Other items

### data_in 

#### Source audio

Nano33BLESense_Audio.zip containing wav files as a subset of the speech_commands category set, created by myself. 

This audio was used as source data to train the SB-CNN (49x40) model.

#### arduino_pdm

Simple sketch to listen using the PDM microphone then dump audio to Serial.  This was used to acquire the source audio for tesrting using a Nano 33 BLE Sense.

### data_out

Example output acquired from the SB-CNN (49x40) model, using the micro_speech_one sketch on a Nano 33 BLE Sense.

It contains txt files which were captured using a python script.  Each 'txt' file contains a single result when the button was clicked, and includes the inference result output tensor, raw 16000 audio samples of sined int16 precision and the input feature as created by the micro_frontend as a 49x40 array (1960 samples of signed int8 precision).

For example `results_0001_no_no.txt` 
- was the first (0001) record
- the target word was `no` (first `no` in filename) 
- it was inferred as `no` (second `no` in filename)
  - Output is a 2 x 1 tensor with a softmax int8 value  
  - `AvgScore 0` = `no` with a score of 26 (int8) 
  - `AvgScore 1` = `yes` with as score of -26 (int8) 
- some debugging preample is at the top of each file
- As the score exceeds 20, the recognizer reports `Heard no (26) @ &lt;time&gt; ms
- feature data set follows 'x y value'
- raw audio follows, as 'Audio &lt;pos&gt; @ &lt;PCM value&gt; (int16_t = -32768 to 32767)'

```
Pressed
Feature requested..
Feature not recording
Recording initialized
Recording started
Feature recording
Feature Check
Feature Retrieved
Retrieved feature
Score 0 0 26
Score 0 1 -26
AvgScore 0 26
AvgScore 1 -26
Heard no (26) @11968ms
0 0 117
0 1 86
0 2 90
0 3 79
0 4 99
...
48 37 0
48 38 0
48 39 0
Audio 0 @ 248
Audio 1 @ 157
Audio 2 @ 172
Audio 3 @ 114
...
Audio 16381 @ -126
Audio 16382 @ -145
Audio 16383 @ -125
Complete
```

**LICENCE**

All audio samples and output result data provided here may be used for research purposes only.  Commercial use is strictly forbidden.

https://creativecommons.org/licenses/by-nc/3.0/au/

All source code is provided without warranty, and attribution must be provided if used to the original authors.  For specific licence conditions, see the source file headers.
