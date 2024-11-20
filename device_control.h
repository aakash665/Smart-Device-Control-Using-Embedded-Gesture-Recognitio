#ifndef DEVICE_CONTROL_H
#define DEVICE_CONTROL_H

void deviceControlInit() {
  pinMode(LED_PIN, OUTPUT);
}

void executeControl(int gestureId) {
  switch (gestureId) {
    case 0:
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Gesture 0: Turned LED ON.");
      break;
    case 1:
      digitalWrite(LED_PIN, LOW);
      Serial.println("Gesture 1: Turned LED OFF.");
      break;
    default:
      Serial.println("No action mapped for this gesture.");
      break;
  }
}

#endif  
