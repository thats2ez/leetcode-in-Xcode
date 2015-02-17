//
//  Length of Last Word.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/16/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        bool word = false;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                word = true;
            } else if (word) {
                return len - i - 1;
            }else {
                len = i;
            }
            
        }
        return word ? len : 0;
    }
};