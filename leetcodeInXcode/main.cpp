//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Different Ways to Add Parentheses.h"

int main() {


    Solution s;
    auto result = s.diffWaysToCompute("0+1");
    for (auto i : result) {
        cout << i << endl;
    }
    return 0;
}