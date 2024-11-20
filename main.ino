#include "imu_sensor.h"
#include "gesture_classifier.h"
#include "device_control.h"
#include "utils.h"

#define LED_PIN 13  

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  if (!imuInit()) {
    Serial.println("IMU initialization failed!");
    while (1);
  }

  if (!gestureModelInit()) {
    Serial.println("Gesture model initialization failed!");
    while (1);
  }

  deviceControlInit();
  Serial.println("Setup complete. Ready for gestures.");
}

void loop() {
  float imuData[6];  
  if (!readIMUData(imuData)) {
    Serial.println("Failed to read IMU data!");
    delay(100);
    return;
  }

  int gestureId = classifyGesture(imuData);

  if (gestureId != -1) {
    executeControl(gestureId);
  }

  delay(100);  // Small delay for processing
}
