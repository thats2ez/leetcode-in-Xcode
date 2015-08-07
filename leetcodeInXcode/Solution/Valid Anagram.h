//
//  Valid Anagram.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 8/7/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Valid_Anagram_h
#define Valid_Anagram_h

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> occur(26, 0);
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            occur[index]++;
        }
        for (int i = 0; i < t.length(); i++) {
            int index = t[i] - 'a';
            if (--occur[index] < 0) return false;
        }
        return true;
    }
};

#endif /* Valid_Anagram_h */
