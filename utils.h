#ifndef UTILS_H
#define UTILS_H

void printIMUData(float *imuData) {
  Serial.print("Accelerometer: ");
  Serial.print(imuData[0]); Serial.print(", ");
  Serial.print(imuData[1]); Serial.print(", ");
  Serial.println(imuData[2]);

  Serial.print("Gyroscope: ");
  Serial.print(imuData[3]); Serial.print(", ");
  Serial.print(imuData[4]); Serial.print(", ");
  Serial.println(imuData[5]);
}

#endif  