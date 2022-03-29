#pragma once
#include <string>

typedef enum sensor_type
{
  EN_12_BIT_SENSOR = 0,
  EN_10_BIT_SENSOR = 1
}enSensorType;

unsigned getMaxVoltage(enSensorType oSensorType)
{
  if(oSensorType == enSensorType::EN_12_BIT_SENSOR)
    return 4094;
  else
    return 1023;
}
