//
//  Isomorphic Strings.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/18/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, char> dict;
        unordered_map<char, char> reverse;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i];
            char b = t[i];
            
            if (dict.find(a) != dict.end()) {
                if (dict[a] != b) return false;
                if (reverse.find(b) == reverse.end() || reverse[b] != a) return false;
            } else {
                if (reverse.find(b) != reverse.end()) return false;
            }
            
            dict[a] = b;
            reverse[b] = a;
        }
        return true;
    }
};