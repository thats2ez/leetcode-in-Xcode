//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Longest Palindromic Substring.h"

int main() {
    Solution s;
    string str("aaabaaaa");
    str = "bb";
//    str = "abb";
    str = "ccd";
    auto result = s.longestPalindrome(str);
    cout << result << endl;
    return 0;
}