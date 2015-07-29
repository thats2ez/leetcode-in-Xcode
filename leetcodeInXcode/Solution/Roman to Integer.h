//
//  Roman to Integer.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/28/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Roman_to_Integer_h
#define Roman_to_Integer_h

class Solution {
public:
    int romanToInt(string s) {
        vector<string> pattern = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int result = 0;
        int j = 0;
        for (int i = 0; i < s.length();) {
            for (;j < pattern.size(); j++) {
                if (s.compare(i, pattern[j].length(), pattern[j]) == 0) {
                    result += value[j];
                    i += pattern[j].length();
                    break;
                }
            }
            // not matched
            if (j == pattern.size()) break;
        }
        return result;
    }
};

#endif /* Roman_to_Integer_h */
