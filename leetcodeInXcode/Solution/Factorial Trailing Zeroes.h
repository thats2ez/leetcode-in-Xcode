//
//  Factorial Trailing Zeroes.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/31/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int trailingZeroes(int n) {
        int d = 5;
        int result = 0;
        while (n >= d) {
            int q = n / d;
            result += q;
            if (INT_MAX / 5 < d)
                break;
            d *= 5;
        }
        return result;
    }
};