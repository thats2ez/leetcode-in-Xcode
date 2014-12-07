//
//  Subsets II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/6/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        vector<vector<int>> result;
        sort(S.begin(), S.end());
        for (int i = 0; i < pow(2, S.size()); i++) {
            permutate(result, S, i);
        }
        return result;
    }
    
    void permutate(vector<vector<int>> &result, vector<int> &S, int pattern) {
        for (int i = 0, bit = 1; i < S.size() - 1; i++, bit <<= 1) {
            if ((S[i] == S[i+1]) && !(pattern & bit) && (pattern & (bit << 1))) {
                return;
            }
        }
        vector<int> subset;
        for (int i = 0; i < S.size(); i++, pattern >>= 1) {
            if (pattern & 1) {
                subset.push_back(S[i]);
            }
        }
        result.push_back(subset);
    }
};