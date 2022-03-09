#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef std::pair<int,int> RangePair;
typedef std::map<RangePair, int> SingleRangePairResult; // type to store result corresponding to a particular range.
typedef std::vector<SingleRangePairResult> oRangeCheckResults;  

oRangeCheckResults CalculateReadingsAndRangeFromValues(std::vector<int> &rfInputValues);

