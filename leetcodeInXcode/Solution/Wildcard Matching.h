//
//  Wildcard Matching.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/13/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
//    bool isMatch(const char *c_s, const char *c_p) {
//        char *s = (char *)c_s, *p = (char *)c_p;
//        char *pre_s = nullptr, *pre_p = nullptr;
//        // pattern not empty or can backtrack
//        while (*p || pre_s) {
//            // pattern not '*' while s is end
//            if (!*s && *p != '*') {
//                return !*p;
//            }
//            if (*p == '*') {
//                p++;
//                // next backtrack entrance
//                pre_s = s;
//                pre_p = p;
//                continue;
//            }
//            if( *s == *p || *p == '?') {
//                // match one-to-one
//                s++;
//                p++;
//                continue;
//            }
//            // backtrack
//            if (pre_s) {
//                s = ++pre_s;
//                p = pre_p;
//                // backtrack ends
//                if (!*pre_s)
//                    pre_s = nullptr;
//                continue;
//            }
//            return false;
//        }
//        // only p is used up
//        return !*s;
//    }
    
    bool isMatch(const char *c_s, const char *c_p) {
        char *s = (char *)c_s, *p = (char *)c_p;
        char *next_s = nullptr, *next_p = nullptr;
        while (*s) {
            if (*p == '*') {
                next_s = s+1;
                next_p = ++p;
                continue;
            }
            if (*p == '?' || *p == *s) {
                s++;
                p++;
                continue;
            }
            if (next_s) {
                s = next_s++;
                p = next_p;
                continue;
            }
            return false;
        }
        while (*p=='*') {
            p++;
        }
        return !*p;
    }
};