//
//  Reverse Bits.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/17/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 1, j = 1 << 31;
        while (i < j) {
            // get two bits
            bool a = i & n, b = j & n;
            
            // reset these two digits to 0
            n &= (~0) ^ (i | j);
            
            // set two new value
            if (a) n |= j;
            if (b) n |= i;
            
            // move the two pattern bits
            i <<= 1, j >>= 1;
        }
        return n;
    }
};