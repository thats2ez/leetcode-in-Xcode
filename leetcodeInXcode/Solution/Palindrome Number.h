//
//  Palindrome Number.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/17/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int d = 1;
        while (d <= x/10) {
            d *= 10;
        }
        while (x > 0) {
            int q = x / d;
            int r = x % 10;
            if (q != r) {
                return false;
            }
            x = (x % d) / 10;
            d /= 100;
        }
        return true;
    }
};