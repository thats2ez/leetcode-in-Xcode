//
//  Decode Ways.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 1/4/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.length();
        vector<int> opt(n+1, 0);
        opt[n] = 1;
        for (int i = n-1; i >= 0; i--) {
            opt[i] = (s[i] >= '1' && s[i] <= '9') ? opt[i+1] : 0;
            if ((i < n-1) &&
                (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
                opt[i] += opt[i+2];
            }
        }
        return opt[0];
    }
};