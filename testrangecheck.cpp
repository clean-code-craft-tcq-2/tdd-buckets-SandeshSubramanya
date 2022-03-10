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
