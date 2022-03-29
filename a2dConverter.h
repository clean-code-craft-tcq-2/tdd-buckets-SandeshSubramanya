#pragma once
#include <string>
#include <math.h>
using namespace std;

typedef enum sensor_type
{
  EN_12_BIT_SENSOR = 0,
  EN_10_BIT_SENSOR = 1
}enSensorType;

unsigned getMaxVoltage(enSensorType oSensorType)
{
  if(oSensorType == enSensorType::EN_12_BIT_SENSOR)
    return 4094;
}

int getAmphere(int InputValue, enSensorType oSensorType)
{
  double voltage = getMaxVoltage(oSensorType);
  double Ampheres = 10 * (float(InputValue)/voltage);
  return int(round(Ampheres));
}
