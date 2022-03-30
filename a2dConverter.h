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
        return (0 <= InputValue && InputValue <= MAX_12_BIT_VOLTAGE_READING);
}

/* 
Retuns list of correspondng amp reading from the given A2D reported values.
The function ignores any errorneous input readings in A2D and converts only valid values.
*/
vector<int> ConvertA2DInputValuesToAmpheres(const vector<int> &rfA2DInputValue, enSensorType oSensorType)
{
    vector<int> oResultValuesInAmps;
    for(int InputVal: rfA2DInputValue)
    {
        if(isReadingValid(InputVal,oSensorType))
        {
            oResultValuesInAmps.push_back(getAmphere(InputVal));
        }   
    }
    return oResultValuesInAmps;
}
