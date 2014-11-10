//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "First Missing Positive.h"

int main() {
    Solution s;
    int array[] = {1,1};
    cout << s.firstMissingPositive(array, sizeof(array) / sizeof(int)) << endl;
    return 0;
}