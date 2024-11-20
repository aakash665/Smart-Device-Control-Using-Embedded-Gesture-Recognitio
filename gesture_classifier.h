#ifndef GESTURE_CLASSIFIER_H
#define GESTURE_CLASSIFIER_H

#include "tflite_model.h"

bool classifyAndExecute(float *imuData) {
  int gestureId = classifyGesture(imuData);

  if (gestureId == -1) {
    Serial.println("Gesture not recognized.");
    return false;
  }

  Serial.print("Detected gesture: ");
  Serial.println(gestureId);
  return true;
}

#endif  
