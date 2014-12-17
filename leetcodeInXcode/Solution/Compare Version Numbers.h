//
//  Compare Version Numbers.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/16/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int compareVersion(string version1, string version2) {\
        // pos of next token
        int token1 = 0, token2 = 0;
        do {
            // end pos
            int end1 = nextToken(version1, token1);
            int end2 = nextToken(version2, token2);
            int number1 = getNumber(version1, token1, end1);
            int number2 = getNumber(version2, token2, end2);
            if (number1 != number2) {
                return number1 > number2 ? 1 : -1;
            }
            token1 = end1+1;
            token2 = end2+1;
        } while (token1 < version1.length() || token2 < version2.length());
        return 0;
    }
    // get end pos of token, return end of string if none
    int nextToken(const string &str, int start) {
        if (start >= str.length())
            return str.length();
        int pos = str.find('.', start);
        return pos == string::npos ? str.length() - 1 : pos;
    }
    
    // get number by pos, return 0 if outbound
    int getNumber(const string &str, int start, int end) {
        if (start >= str.length())
            return 0;
        return stoi(str.substr(start, end - start + 1));
    }
};