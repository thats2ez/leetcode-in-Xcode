//
//  Ugly Number.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 8/20/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Ugly_Number_h
#define Ugly_Number_h

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        vector<int> factors = {2, 3, 5};
        for (int factor : factors) {
            while (num % factor == 0) {
                num /= factor;
            }
        }
        return num == 1;
    }
};

#endif /* Ugly_Number_h */
