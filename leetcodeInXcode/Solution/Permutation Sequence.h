//
//  Permutation Sequence.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/23/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> unuse;
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            unuse.push_back(i);
            fact *= i;
        }
        string s;
        k--;
        for (int i = 0; i < n; i++) {
            fact /= (n - i);
            int order = k / fact;
            for(auto it = unuse.begin(); it != unuse.end(); it++) {
                if (*it == 0) {
                    continue;
                }
                if (order-- == 0) {
                    s.push_back('0' + *it);
                    *it = 0;
                    break;
                }
            }
            k = k % fact;
        }
        return s;
    }
};