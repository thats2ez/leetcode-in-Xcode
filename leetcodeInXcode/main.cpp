//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Course Schedule II.h"

int main() {
    Solution s;
    vector<pair<int, int>> prerequisites{pair<int, int>(1, 0)};
    auto result = s.findOrder(2, prerequisites);
    return 0;
}