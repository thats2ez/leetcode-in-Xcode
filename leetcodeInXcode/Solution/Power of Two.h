//
//  Power of Two.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/24/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Power_of_Two_h
#define Power_of_Two_h

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n-1));
    }
};

#endif /* Power_of_Two_h */
