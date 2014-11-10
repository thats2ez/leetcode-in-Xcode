//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Merge Intervals.h"

int main() {
    Solution s;
    vector<Interval> v{Interval(1,4),Interval(1,5)};
    auto result = s.merge(v);
    return 0;
}