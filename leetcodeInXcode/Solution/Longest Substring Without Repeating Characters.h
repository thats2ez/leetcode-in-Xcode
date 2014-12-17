//
//  Longest Substring Without Repeating Characters.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/15/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int CHARSET_SIZE = 128;
        vector<int> count(CHARSET_SIZE, 0);
        int l = 0;
        for (int i = 0, j = -1; j < int(s.length());) {
            if (valid(count)) {
                int length = j - i + 1;
                if (length > l) {
                    l = length;
                }
                if (++j < s.length()) {
                    count[s[j]]++;
                }
                if (length < CHARSET_SIZE) {
                    continue;
                }
            }
            count[s[i]]--;
            i++;
        }
        return l;
    }
    
    bool valid(vector<int> &count) {
        for(int i = 0; i < count.size(); i++) {
            if (count[i] > 1) {
                return false;
            }
        }
        return true;
    }
};