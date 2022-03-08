#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "rangecheck.h"
using namespace std;


TEST_CASE(" Test Smallest Possible range") 
{
  // test the code intially with the smallest range pair.
  RangePair oPair(4, 5);  
  SingleRangePairResult oNumbersInRanges;
  oNumbersInRanges.insert({oPair, 2});
  oRangeCheckResults oExpectedResult {oNumbersInRanges};
}
