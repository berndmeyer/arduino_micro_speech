/*
  This example reads audio data from the on-board PDM microphones, and prints
  out the samples to the Serial console. The Serial Plotter built into the
  Arduino IDE can be used to plot the audio data (Tools -> Serial Plotter)

  Circuit:
  - Arduino Nano 33 BLE board

  This example code is in the public domain.
*/

#include <PDM.h>

// buffer to read samples into, each sample is 16-bits

#define BUFFER_SIZE 256
#define LONG_BUFFER_SIZE (22400 * 1) 

short sampleBuffer[BUFFER_SIZE];
short longSampleBuffer[LONG_BUFFER_SIZE];

// number of samples read
volatile int samplesRead;
volatile int bufferOffset = 0;

void setup() {
  // Start Serial transmission with error checking
  Serial.begin(500000,SERIAL_8O1);
  while (!Serial);

  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(LEDR,OUTPUT);
  pinMode(LEDG,OUTPUT);
  pinMode(LEDB,OUTPUT);

  // configure the data receive callback
  PDM.onReceive(onPDMdata);

  // initialize PDM with:
  // - one channel (mono mode)
  // - a 16 kHz sample rate
  if (!PDM.begin(1, 16000)) {
    Serial.println("Failed to start PDM!");
    while (1);
  }

  // Gain must be set, after PDM.begin
  PDM.setGain(0x50);
}

void loop() {
  // wait for samples to be read
  if (bufferOffset < LONG_BUFFER_SIZE) {
    digitalWrite(LED_BUILTIN,HIGH);
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDB,LOW);
    
    // Acquire samples
    if (samplesRead) {

      // print samples to the serial monitor or plotter
      for (int i = 0; i < samplesRead && bufferOffset < LONG_BUFFER_SIZE; i++) {
        longSampleBuffer[bufferOffset] = sampleBuffer[i];
        bufferOffset += 1;
      }
  
      // clear the read count
      samplesRead = 0;
    }
  }

  if (bufferOffset >= LONG_BUFFER_SIZE) {
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDB,HIGH);
    // Transmit samples
    for (int i = 0; i < LONG_BUFFER_SIZE; i++) {      
      Serial.println(longSampleBuffer[i]);
    }

    bufferOffset = 0;
  }
}

void onPDMdata() {
  // query the number of bytes available
  int bytesAvailable = PDM.available();

  // read into the sample buffer
  PDM.read(sampleBuffer, bytesAvailable);

  // 16-bit, 2 bytes per sample
  samplesRead = bytesAvailable / 2;
}
