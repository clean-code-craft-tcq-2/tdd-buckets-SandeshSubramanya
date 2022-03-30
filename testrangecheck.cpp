#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "rangecheck.h"
#include "a2dConverter.h"

using namespace std;

TEST_CASE(" Test Smallest Possible range") 
{
  // test the code intially with the smallest range pair.
  vector<int> oInputValues {4,5};
  oRangeCheckResults oCalculatedResults = CalculateReadingsAndRangeFromValues(oInputValues);
  int num_of_readings = 0;
  int start_of_range = 0;
  int end_of_range = 0;
  if(!oCalculatedResults.empty())
  {
    SingleRangePairResult oCalculatedNumbersInRange = oCalculatedResults[0];  // get the map info.
    start_of_range = oCalculatedNumbersInRange.begin()->first.first;
    end_of_range = oCalculatedNumbersInRange.begin()->first.second;
    num_of_readings = oCalculatedNumbersInRange.begin()->second;
  }
  assert(start_of_range == 4);
  assert(end_of_range == 5);
  assert(num_of_readings == 2);
}

TEST_CASE("Test Range check functionality with several input values") 
{
  vector<int> oInputValues {12,18,15,12,14,13,125,180,165,200};
  oRangeCheckResults oRangeCheckResultsExpected;  // create a vector with expected values to compare.
  
  SingleRangePairResult oTotalNumbersInRanges;
  oTotalNumbersInRanges.insert({{12, 15}, 5});
  oRangeCheckResultsExpected.push_back(oTotalNumbersInRanges);
  oTotalNumbersInRanges.clear();
  
  oTotalNumbersInRanges.insert({{18, 18}, 1});
  oRangeCheckResultsExpected.push_back(oTotalNumbersInRanges);
  oTotalNumbersInRanges.clear();
  
  oTotalNumbersInRanges.insert({{125, 125}, 1});
  oRangeCheckResultsExpected.push_back(oTotalNumbersInRanges);
  oTotalNumbersInRanges.clear();
  
  oTotalNumbersInRanges.insert({{165, 165}, 1});
  oRangeCheckResultsExpected.push_back(oTotalNumbersInRanges);
  oTotalNumbersInRanges.clear();
  
  oTotalNumbersInRanges.insert({{180, 180}, 1});
  oRangeCheckResultsExpected.push_back(oTotalNumbersInRanges);
  oTotalNumbersInRanges.clear();
  
  oTotalNumbersInRanges.insert({{200, 200}, 1});
  oRangeCheckResultsExpected.push_back(oTotalNumbersInRanges);
  oTotalNumbersInRanges.clear();
  
  oRangeCheckResults oCalculatedResults = CalculateReadingsAndRangeFromValues(oInputValues);
  assert(oCalculatedResults.size() == oRangeCheckResultsExpected.size());
  
  // check whether the calculated occurence in the range is as expected.
  std::vector<SingleRangePairResult>::iterator itrCalculatedResult = oCalculatedResults.begin();
  std::vector<SingleRangePairResult>::iterator itrExpectedResult = oRangeCheckResultsExpected.begin();
  
  for(; (itrCalculatedResult!=oCalculatedResults.end() && itrExpectedResult != oRangeCheckResultsExpected.end()); ++itrCalculatedResult,++itrExpectedResult)
  {
    assert(itrCalculatedResult->begin()->first.first == itrExpectedResult->begin()->first.first); //Range start comparison
    assert(itrCalculatedResult->begin()->first.second == itrExpectedResult->begin()->first.second);  //Range end comparison
    assert(itrCalculatedResult->begin()->second == itrExpectedResult->begin()->second); // number of readings.
  }
}

TEST_CASE(" Test With Single Element") 
{
  // test the code intially with the smallest range pair.
  vector<int> oSingleInputValue {4};
  oRangeCheckResults oCalculatedResults = CalculateReadingsAndRangeFromValues(oSingleInputValue);
  int numReadings = 0;
  int startOfRange = 0;
  int endOfRange = 0;
  if(!oCalculatedResults.empty())
  {
    SingleRangePairResult oCalculatedNumbersInRange = oCalculatedResults[0];  // get the map info.
    startOfRange = oCalculatedNumbersInRange.begin()->first.first;
    endOfRange = oCalculatedNumbersInRange.begin()->first.second;
    numReadings = oCalculatedNumbersInRange.begin()->second;
  }
  assert(startOfRange == 4);
  assert(endOfRange == 4);
  assert(numReadings == 1);
}

TEST_CASE(" Test correctness of amphere calculation from given Input") 
{
  {
    int InputValue {1046};
    enSensorType oSensorType = sensor_type::EN_12_BIT_SENSOR;
    int expectedValue_amps = 3;
    int calculated_value_amps= getAmphere(InputValue,oSensorType);
    assert(expectedValue_amps == calculated_value_amps);
  }
  
  {
    int InputValue {0};
    enSensorType oSensorType = sensor_type::EN_12_BIT_SENSOR;
    int expectedValue_amps = 0;
    int calculated_value_amps= getAmphere(InputValue,oSensorType);
    assert(expectedValue_amps == calculated_value_amps);
  }
  
  {
    int InputValue {4094};
    enSensorType oSensorType = sensor_type::EN_12_BIT_SENSOR;
    int expectedValue_amps = 10;
    int calculated_value_amps= getAmphere(InputValue,oSensorType);
    assert(expectedValue_amps == calculated_value_amps);
  }
}

TEST_CASE(" Test Validity of Input value for A2D converter") 
{
  {
    int InputValue {4094};
    enSensorType oSensorType = sensor_type::EN_12_BIT_SENSOR;
    bool calculatedValue = isReadingValid(InputValue,oSensorType);
    assert(calculatedValue == true);
  }

  {
    int InputValue {0};
    enSensorType oSensorType = sensor_type::EN_12_BIT_SENSOR;
    bool calculatedValue = isReadingValid(InputValue,oSensorType);
    assert(calculatedValue == true);
  }
  
  {
    int InputValue {5000};
    enSensorType oSensorType = sensor_type::EN_12_BIT_SENSOR;
    bool calculatedValue = isReadingValid(InputValue,oSensorType);
    assert(calculatedValue == false);
  }
  
  {
    int InputValue {-100};
    enSensorType oSensorType = sensor_type::EN_12_BIT_SENSOR;
    bool calculatedValue = isReadingValid(InputValue,oSensorType);
    assert(calculatedValue == false);
  }  
}


TEST_CASE(" Test converter for a list of A2D input Values:") 
{
  {
    vector<int> oInputValues {0,-152,4800,4600,5000,4000,1000};
    vector<int> oExpectedValues {0,10,2};
    enSensorType oSensorType = sensor_type::EN_12_BIT_SENSOR;
    vector<int> oCalculatedValues = ConvertA2DInputValuesToAmpheres(oInputValues,oSensorType);
    assert(calculatedValue == oExpectedValues);
  }
  
}

