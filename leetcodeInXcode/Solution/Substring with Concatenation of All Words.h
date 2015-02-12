////
////  Substring with Concatenation of All Words.h
////  leetcodeInXcode
////
////  Created by Kaiqi on 11/22/14.
////  Copyright (c) 2014 edu.self. All rights reserved.
////
//
//class Solution {
//public:
//    vector<int> findSubstring(string S, vector<string> &L) {
//        vector<int> result;
//        if (L.size() == 0) {
//            return result;
//        }
//        
//        unordered_map<string, int> expected;
//        for (string word : L) {
//            expected[word]++;
//        }
//        int n = L.size(), m = L[0].size();
//        for (int k = 0; k < m; k++) {
//            unordered_map<string, int> occurrence;
//            int words = 0;
//            for (int i = 0; k + (i * m) + (m - 1) < S.size(); i++) {
//                int idx = k + (i * m);
//                if (expected.find(S.substr(idx, m)) == expected.end()) {
//                    occurrence.clear();
//                    words = 0;
//                    continue;
//                }
//                // add new one
//                occurrence[S.substr(idx, m)]++;
//                words++;
//                
//                if (words == n + 1) {
//                    // remove old one
//                    int old_idx = k + (i - n) * m;
//                    occurrence[S.substr(old_idx, m)]--;
//                    words--;
//                }
//                
//                // check
//                if (isValid(expected, occurrence)) {
//                    result.push_back(k + (i - n + 1) * m);
//                }
//            }
//        }
//        return result;
//    }
//    
//    bool isValid(const unordered_map<string, int> &expected, const unordered_map<string, int> &occurrence) {
//        for(auto it_e = expected.begin(); it_e != expected.end(); it_e++) {
//            auto it = occurrence.find(it_e->first);
//            if (it == occurrence.end() || it_e->second != it->second) {
//                return false;
//            }
//        }
//        return true;
//    }
//};

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        int len = L[0].size();
        int n = L.size();
        if (L.empty() || n == 0) return result;
        // count needed occurrence for words
        unordered_map<string, int> found, need;
        for (int i = 0; i < n; i++) {
            need[L[i]]++;
        }
        int unique = need.size();
        
        for (int offset = 0; offset < len; offset++) {
            found.clear();
            int count = 0;
            for (int i = offset; i + len - 1 < S.size(); i += len) {
                string token = S.substr(i, len);
                if (i - len * n >= 0) {
                    string out = S.substr(i - len * n, len);
                    if (need[out] > 0) {
                        if (found[out]-- == need[out]) count--;
                        else if (found[out] == need[out]) count++;
                    }
                }
                if (need[token] == 0) {
                    ;
                } else if (found[token] < need[token]) {
                    if (++found[token] == need[token]) count++;
                } else {
                    if (found[token]++ == need[token]) count--;
                }
                if (count == unique) result.push_back(i - len * n + len);
            }
        }
        return result;
    }
};