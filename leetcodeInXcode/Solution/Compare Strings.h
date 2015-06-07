//
//  Compare Strings.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/7/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        auto a = signature(A);
        auto b = signature(B);
        for (auto p : b) {
            if (a[p.first] < p.second) return false;
        }
        return true;
    }
    
    // int32_t signature(const string &str) {
    //     int32_t result = 0;
    //     for (char c : str) {
    //         result |= (1 << (c - 'A'));
    //     }
    //     return result;
    // }
    
    unordered_map<char, int> signature(const string &str) {
        unordered_map<char, int> result;
        for (char c : str) {
            result[c]++;
        }
        return result;
    }
};

