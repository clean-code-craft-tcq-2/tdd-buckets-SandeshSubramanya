#pragma once
#include <string>
#include <math.h>
using namespace std;

#define MAX_12_BIT_VOLTAGE_READING 4094

typedef enum sensor_type
{
  EN_12_BIT_SENSOR = 0,
  EN_10_BIT_SENSOR = 1
}enSensorType;

unsigned getMaxVoltage(enSensorType oSensorType)
{
  if(oSensorType == enSensorType::EN_12_BIT_SENSOR)
    return (int)MAX_12_BIT_VOLTAGE_READING;
}

int getAmphere(int InputValue, enSensorType oSensorType)
{
  double voltage = getMaxVoltage(oSensorType);
  double Ampheres = 10 * (float(InputValue)/voltage);
  return int(round(Ampheres));
}

bool isReadingValid(int InputValue, enSensorType oSensorType)
{
    if(oSensorType == enSensorType::EN_12_BIT_SENSOR)
        return (InputValue >=0 && InputValue >= MAX_12_BIT_VOLTAGE_READING);
}
