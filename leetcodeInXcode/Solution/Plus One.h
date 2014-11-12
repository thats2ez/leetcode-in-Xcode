//
//  Plus One.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/12/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int i=digits.size()-1;
        for(; i >= 0 ; i--) {
            if(digits[i] != 9) {
                digits[i]++;
                break;
            }
            digits[i] = 0;
        }
        if (i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};