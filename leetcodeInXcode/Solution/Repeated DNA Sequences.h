//
//  Repeated DNA Sequences.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/16/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int32_t, int> occur;
        vector<string> result;
        for (int i = 0; i < s.length(); i++) {
            // end point
            if (i + window > s.length()) break;
            
            int32_t h = hash(s, i);
            if (h < 0) break;
            
            auto it = occur.find(h);
            if (it != occur.end()) {
                // if previously found
                if (it->second >= 0) {
                    // if second time found
                    result.push_back(s.substr(i, window));
                    it->second = -1;
                }
            } else {
                // if not found
                occur[h] = i;
            }
        }
        return result;
    }
    
private:
    const static int window = 10;
    int32_t hash(const string &s, int start) {
        if (start + window > s.length()) {
            return -1;
        }
        int32_t hash = 0;
        for (int i = 0; i < window; i++) {
            int pattern = 0;
            switch (s[start + i]) {
                case 'A':
                    pattern = 1;
                    break;
                case 'C':
                    pattern = 2;
                    break;
                case 'G':
                    pattern = 3;
                    break;
                default: // 'T'
                    break;
            }
            hash |= pattern << (2 * i);
        }
        return hash;
    }
};

