#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

typedef std::pair<int,int> RangePair;
typedef std::map<RangePair, int> SingleRangePairResult; // type to store result corresponding to a particular range.
typedef std::vector<SingleRangePairResult> oRangeCheckResults;  

TEST_CASE(" Test Smallest Possible range") 
{
  // test the code intially with the smallest range pair.
  RangePair oPair(4, 5);  
  SingleRangePairResult oNumbersInRanges;
  oNumbersInRanges.insert({oPair, 2});
  oRangeCheckResults oExpectedResult {oNumbersInRanges};
}
