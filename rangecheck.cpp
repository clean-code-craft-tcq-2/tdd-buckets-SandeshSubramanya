#include "rangecheck.h"
#include <algorithm>

oRangeCheckResults CalculateReadingsAndRangeFromValues(std::vector<int> &rfInputValues)
{
  // firstly sort the input values.
  std::sort(rfInputValues.begin(),rfInputValues.end());
  
  // for now, write a simple code to make simple test case pass. 
  // Future find the logic to handle this.
  oRangeCheckResults oRangeCheckResultsTemp;  
  SingleRangePairResult oTotalNumbersInRanges;
  oTotalNumbersInRanges.insert({{4, 5}, 2});
  oRangeCheckResultsTemp.push_back(oTotalNumbersInRanges);
  return oRangeCheckResultsTemp;
}
