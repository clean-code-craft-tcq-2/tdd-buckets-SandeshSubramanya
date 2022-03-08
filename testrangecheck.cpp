#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "rangecheck.h"
using namespace std;


TEST_CASE(" Test Smallest Possible range") 
{
  // test the code intially with the smallest range pair.
  vector<int> oInputValues {4,5};
  
  //create expected values information.
  SingleRangePairResult oTotalNumbersInRanges;
  oTotalNumbersInRanges.insert({{4, 5}, 2});  // 2-> number of expected entries in range 4,5
  oRangeCheckResults oExpectedResult {oTotalNumbersInRanges};
  
  // calculate results.
  oRangeCheckResults oCalculatedResults = DetermineRange(oInputValues);
  SingleRangePairResult oCalculatedNumbersInRange = oCalculatedResults[0];
  
  assert(oCalculatedNumbersInRange.begin()->second == 2); // number of elements in the range is expected to be 2.
  
}
