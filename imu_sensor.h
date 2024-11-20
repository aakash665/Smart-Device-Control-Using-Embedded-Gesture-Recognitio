#ifndef IMU_SENSOR_H
#define IMU_SENSOR_H

#include <Arduino_LSM9DS1.h>  

bool imuInit() {
  if (!IMU.begin()) {
    return false;
  }
  Serial.println("IMU initialized.");
  return true;
}

bool readIMUData(float *imuData) {
  float ax, ay, az;  
  float gx, gy, gz;  

  if (!IMU.accelerationAvailable() || !IMU.gyroscopeAvailable()) {
    return false;
  }

  IMU.readAcceleration(ax, ay, az);
  IMU.readGyroscope(gx, gy, gz);

  imuData[0] = ax; imuData[1] = ay; imuData[2] = az;
  imuData[3] = gx; imuData[4] = gy; imuData[5] = gz;

  return true;
}

#endif 