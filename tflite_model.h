#ifndef TFLITE_MODEL_H
#define TFLITE_MODEL_H

#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"

#include "gesture_model_data.h"

namespace {
  constexpr int kTensorArenaSize = 8 * 1024; 
  uint8_t tensorArena[kTensorArenaSize];

  tflite::MicroInterpreter *interpreter = nullptr;
  TfLiteTensor *input = nullptr;
  TfLiteTensor *output = nullptr;
}

bool gestureModelInit() {
  static tflite::MicroMutableOpResolver<5> resolver;
  resolver.AddFullyConnected();
  resolver.AddSoftmax();
  resolver.AddReshape();

  const tflite::Model *model = tflite::GetModel(g_gesture_model_data);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    Serial.println("Model schema version mismatch!");
    return false;
  }

  static tflite::MicroInterpreter static_interpreter(
      model, resolver, tensorArena, kTensorArenaSize);
  interpreter = &static_interpreter;

  if (interpreter->AllocateTensors() != kTfLiteOk) {
    Serial.println("Failed to allocate tensors!");
    return false;
  }

  input = interpreter->input(0);
  output = interpreter->output(0);

  return true;
}

int classifyGesture(float *imuData) {
  for (int i = 0; i < 6; i++) {
    input->data.f[i] = imuData[i];  
  }

  if (interpreter->Invoke() != kTfLiteOk) {
    Serial.println("Model inference failed!");
    return -1;
  }

  float maxScore = -1;
  int gestureId = -1;
  for (int i = 0; i < output->dims->data[1]; i++) {
    if (output->data.f[i] > maxScore) {
      maxScore = output->data.f[i];
      gestureId = i;
    }
  }

  return gestureId;
}

#endif  
