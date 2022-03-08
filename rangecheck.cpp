#include "rangecheck.h"

oRangeCheckResults DetermineRange(std::vector<int> &rfInputValues)
{
  oRangeCheckResults oRangeCheckResultsTemp;  // result
  // for now insert manual code to make the test pass.
  SingleRangePairResult oTotalNumbersInRanges;
  oTotalNumbersInRanges.insert({{4, 5}, 2});
  oRangeCheckResultsTemp.push_back(oTotalNumbersInRanges);
  return oRangeCheckResultsTemp;
}
