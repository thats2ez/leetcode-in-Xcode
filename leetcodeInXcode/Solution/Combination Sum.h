//
//  Combination Sum.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/25/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        recursiveSum(result, candidates, path, 0, target);
        return result;
    }
    
    void recursiveSum(vector<vector<int> > &result, vector<int> &candidates, vector<int> &path, int valid, int remaining) {
        // valid result
        if (remaining == 0 && !path.empty()) {
            result.push_back(path);
            return;
        }
        
        // for every valid candidates
        for (int i = valid; i < candidates.size() && remaining >= candidates[i]; i++) {
            path.push_back(candidates[i]);
            recursiveSum(result, candidates, path, i, remaining - candidates[i]);
            path.pop_back();
        }
    }
};