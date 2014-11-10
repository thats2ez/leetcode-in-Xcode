//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Insert Interval.h"

int main() {
    Solution s;
    vector<Interval> v{Interval(3,5),Interval(12,15)};
    Interval a(6,6);
    s.insert(v, a);
    return 0;
}