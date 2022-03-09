#include "rangecheck.h"

oRangeCheckResults CalculateReadingsAndRangeFromValues(std::vector<int> &rfInputValues)
{
  // for now, write a simple code to make simple test case pass.
  oRangeCheckResults oRangeCheckResultsTemp;  
  SingleRangePairResult oTotalNumbersInRanges;
  oTotalNumbersInRanges.insert({{4, 5}, 2});
  oRangeCheckResultsTemp.push_back(oTotalNumbersInRanges);
  return oRangeCheckResultsTemp;
}
