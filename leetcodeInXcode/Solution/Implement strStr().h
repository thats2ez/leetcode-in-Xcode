//
//  Implement strStr().h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/11/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        for (int i = 0; i < int(strlen(haystack)) - int(strlen(needle)) + 1; i++) {
            int j = 0;
            for (; needle[j] != 0; j++) {
                if (haystack[i+j] != needle[j]) break;
            }
            if (needle[j] == 0) return i;
        }
        return -1;
    }
};