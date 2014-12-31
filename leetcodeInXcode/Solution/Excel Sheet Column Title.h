//
//  Excel Sheet Column Title.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/31/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    string convertToTitle(int n) {
        vector<char> digits;
        while (n > 0) {
            int r = (n - 1) % 26;
            n = (n - 1) / 26;
            digits.push_back(r + 'A');
        }
        reverse(digits.begin(), digits.end());
        return string(digits.begin(), digits.end());
    }
};