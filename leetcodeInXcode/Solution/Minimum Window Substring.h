//
//  Minimum Window Substring.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/5/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

//class Solution {
//public:
//    string minWindow(string S, string T) {
//        unordered_map<char, int> map;
//        for (char c : T)
//            map[c]--;
//        int min_length = INT_MAX;
//        int result_start = 0;
//        int start = 0;
//        for (int i=0; i < S.length() + 1; map[S[i++]]++) {
//            while (isValid(map)) {
//                if (i - start < min_length) {
//                    min_length = i - start;
//                    result_start = start;
//                }
//                if (map[S[start]] >= 0) {
//                    map[S[start]]--;
//                    start++;
//                }
//            }
//        }
//        return min_length == INT_MAX ? "" : S.substr(result_start, min_length);
//    }
//    
//    bool isValid(unordered_map<char, int> &map) {
//        for (auto pair : map) {
//            if (pair.second < 0)
//                return false;
//        }
//        return true;
//    }
//};