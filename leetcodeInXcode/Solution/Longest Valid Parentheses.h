//
//  Longest Valid Parentheses.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/16/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> opt(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                opt[i+1] = 0;
            } else if (i - 1 >= 0) {
                if (s[i-1] == '(') {
                    opt[i+1] = opt[i-1] + 2;
                } else if (opt[i] > 0 && i - 1 - opt[i] >= 0 && s[i - 1 - opt[i]] == '(') {
                    opt[i+1] = opt[i] + opt[i - 1 - opt[i]] +2;
                }
            }
        }
        
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result = opt[i] > result ? opt[i] : result;
        }
        return result;
    }
    
};