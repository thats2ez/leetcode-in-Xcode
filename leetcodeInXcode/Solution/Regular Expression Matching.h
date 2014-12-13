//
//  Regular Expression Matching.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/12/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        return backtrack(s, p, 0, 0);
    }
    
    bool backtrack(const char *s, const char *p, int i, int j) {
        // if pattern is used up
        if (!p[j])
            return !s[i];
        // match one-to-one
        if (p[j+1] != '*')
            return s[i] && match(s[i], p[j]) && backtrack(s, p, i+1, j+1);
        // match 'x*' with 0 in s
        if (backtrack(s, p, i, j+2))
            return true;
        // match 'x*' with 1 or more
        int k = i;
        while (match(s[k], p[j])) {
            if (backtrack(s, p, ++k, j+2))
                return true;
        }
        return false;
    }
    
    bool match(char a, char b) {
        if (a == b)
            return true;
        if (a != 0 && b == '.')
            return true;
        return false;
    }
};