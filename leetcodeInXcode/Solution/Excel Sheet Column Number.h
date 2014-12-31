//
//  Excel Sheet Column Number.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/31/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for(int i = 0; i < s.length(); i++) {
            number *= 26;
            number += (s[i] - 'A' + 1);
        }
        return number;
    }
};