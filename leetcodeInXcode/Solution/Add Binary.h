//
//  Add Binary.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/17/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        c.reserve(max(a.size(), b.size()));
        for (int i = 0, advance = 0; i < a.size() || i < b.size() || advance > 0; i++) {
            if (i < a.size()) advance += a[i] - '0';
            if (i < b.size()) advance += b[i] - '0';
            if (advance % 2 == 0) {
                c += '0';
            } else {
                c += '1';
            }
            advance /= 2;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};