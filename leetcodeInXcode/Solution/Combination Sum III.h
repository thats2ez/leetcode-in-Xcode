//
//  Combination Sum III.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/25/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k < 0 || k > MAX_DIGIT) return result;
        vector<int> path;
        recursiveSum(result, path, 1, k, n);
        return result;
    }
    
private:
    void recursiveSum(vector<vector<int>> &result, vector<int> path, int start, int k, int n) {
        // success end point
        if (n == 0 && k == 0) {
            result.push_back(path);
            return;
        }
        // failure end point
        if (n <= 0 || k <= 0) return;
        
        // recursive
        int end = MAX_DIGIT - k + 1; // pruning
        for (int i = start; i <= end; i++) {
            path.push_back(i);
            recursiveSum(result, path, i + 1, k - 1, n - i);
            path.pop_back();
        }
    }
    
    static const int MAX_DIGIT = 9;
};