//
//  Bitwise AND of Numbers Range.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/18/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        bool stop = false;
        for (unsigned int pattern = 1 << 31; pattern != 0; pattern >>= 1) {
            if (stop) {
                m &= ~pattern;
            } else if ((m & pattern) ^ (n & pattern)) {
                stop = true;
            }
        }
        return m;
    }
};