//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Count and Say.h"

int main() {
    Solution s;
    for (int i = 0; i < 5; i++) {
        auto result = s.countAndSay(i);
        cout << result << endl;
    }
    return 0;
}