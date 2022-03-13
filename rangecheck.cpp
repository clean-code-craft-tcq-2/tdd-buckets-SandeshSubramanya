#include "rangecheck.h"
#include <algorithm>

unsigned getIndexOfLastElementInContinousRange(unsigned startIndex, const std::vector<int> &rfInputValues, int &count)
{
    unsigned IndexOfLastElementInContinousRange = 0;
    while (
           (startIndex < rfInputValues.size())
           &&
           ((startIndex + 1) < rfInputValues.size())
           )
           {
               if( (rfInputValues[startIndex+1] - rfInputValues[startIndex]) <= 1)
               {
                   // continous range.
                   IndexOfLastElementInContinousRange = startIndex + 1;
                   startIndex = IndexOfLastElementInContinousRange;
                   count++;
               }
               else
               {
                   break; // continous range ends, break
               }
           }
    
    return IndexOfLastElementInContinousRange;
}

oRangeCheckResults CalculateReadingsAndRangeFromValues(std::vector<int> &rfInputValues)
{
  // firstly sort the input values.
  std::sort(rfInputValues.begin(),rfInputValues.end());
    
  oRangeCheckResults oRangeCheckResultsTemp;  
  SingleRangePairResult oTotalNumbersInRanges;
  unsigned int indexOfLastElementInContinousRange = 0;
  int numberOfElementsInCurrentRange = 1;
  for(unsigned startIndex = 0; startIndex < rfInputValues.size(); startIndex +=indexOfLastElementInContinousRange)
  {
      numberOfElementsInCurrentRange =1;
      indexOfLastElementInContinousRange = getIndexOfLastElementInContinousRange(startIndex,rfInputValues, numberOfElementsInCurrentRange);
      if(startIndex < rfInputValues.size() && indexOfLastElementInContinousRange < rfInputValues.size())
      {
          int firstElementInRange =  rfInputValues[startIndex];
          int lastElementInRange =  (indexOfLastElementInContinousRange != 0)?(rfInputValues[indexOfLastElementInContinousRange]):(rfInputValues[startIndex]); // add the start index value itself as the range end.
          SingleRangePairResult oTotalNumbersInRanges;
          oTotalNumbersInRanges.insert({{firstElementInRange, lastElementInRange}, numberOfElementsInCurrentRange});
          oRangeCheckResultsTemp.push_back(oTotalNumbersInRanges);
      }
      ++indexOfLastElementInContinousRange;
  }
  return oRangeCheckResultsTemp;
}
