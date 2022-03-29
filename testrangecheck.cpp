#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "rangecheck.h"
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
