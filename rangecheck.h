#pragma once
#include <iostream>
#include <map>
#include <vector>
typedef std::pair<int,int> RangePair;
typedef std::map<RangePair, int> SingleRangePairResult; // type to store result corresponding to a particular range.
typedef std::vector<SingleRangePairResult> oRangeCheckResults;  

oRangeCheckResults DetermineRange(vector <int> &rfInputValues);

