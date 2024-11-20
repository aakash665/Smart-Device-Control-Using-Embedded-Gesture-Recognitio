# Smart Device Control Using Embedded Gesture Recognition

This project implements a gesture recognition system for smart device control using embedded systems. It uses a lightweight neural network optimized with TensorFlow Lite for Microcontrollers and runs on the Arduino Nano 33 BLE Sense board, enabling real-time gesture classification from IMU sensor data.

---

## Features

- **Gesture Recognition:** Classifies hand gestures using IMU sensor data with high accuracy.
- **Seamless Real-Time Control:** Low-latency responses for smooth device operation.
- **Optimized for Embedded Systems:** Efficient preprocessing and inference for low-power environments.

---

## Hardware Requirements

- **Microcontroller:** Arduino Nano 33 BLE Sense
- **Sensors:** Built-in IMU (Accelerometer, Gyroscope)
- **Power Source:** 5V micro-USB power supply
- **Optional:** A connected smart device to be controlled via gesture inputs.

---

## Software Requirements

- Arduino IDE (Version 1.8.13 or newer)
- TensorFlow Lite for Microcontrollers
- Python (for training and preprocessing scripts)
- Required libraries:
  - `Arduino_TensorFlowLite`
  - `Arduino_LSM9DS1`
  - `Wire`

---

## Project Architecture

1. **Data Collection:** IMU sensor data is captured using the Arduino Nano 33 BLE Sense.
2. **Preprocessing:** Data is preprocessed to ensure compatibility with the ML model.
3. **Model Inference:** TensorFlow Lite interprets the pre-trained ML model to classify gestures.
4. **Device Control:** Classified gestures trigger specific actions on the connected device.

---

## Setup and Installation

### 1. Clone the Repository
```bash
git clone https://github.com/your-username/gesture-control.git
cd gesture-control
