//
//  ZigZag Conversion.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/27/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    string convert(string s, int nRows) {
        
        int pattern = nRows > 1 ? 2 * (nRows - 1) : nRows;
        string result;
        for (int i = 0; i < nRows; i++) {
            string line;
            for (int start = 0; start + i < s.size(); start += pattern) {
                line += s[start + i];
                if (i != 0 && i != nRows - 1) {
                    int second = start + 2 * (nRows - 1) - i;
                    if (second < s.size()) {
                        line += s[second];
                    }
                }
            }
            result += line;
        }
        return result;
    }
};