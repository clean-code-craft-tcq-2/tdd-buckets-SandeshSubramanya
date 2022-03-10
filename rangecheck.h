#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef std::pair<int,int> RangePair;
typedef std::map<RangePair, int> SingleRangePairResult; // type to store result corresponding to a particular range.
typedef std::vector<SingleRangePairResult> oRangeCheckResults;  

unsigned getIndexOfLastElementInContinousRange(unsigned startIndex, const std::vector<int> &rfInputValues, int &count);
oRangeCheckResults CalculateReadingsAndRangeFromValues(std::vector<int> &rfInputValues);

