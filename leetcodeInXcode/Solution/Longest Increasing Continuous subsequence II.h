//
//  Longest Increasing Continuous subsequence II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/30/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        if (A.size() == 0) return 0;
        vector<vector<int>> opt(A.size(), vector<int>(A[0].size(), 0));
        int best = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                best = max(best, recursiveLICS(A, opt, i, j));
            }
        }
        return best;
    }
    
    int recursiveLICS(vector<vector<int>>& A, vector<vector<int>>& opt, int i, int j) {
        if (opt[i][j] > 0) return opt[i][j];
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int result = 1;
        for (int k = 0; k < 4; k++) {
            int a = i + dx[k], b = j + dy[k];
            if (a < 0 || a >= A.size() || b < 0 || b >= A[a].size()) continue;
            if (A[a][b] > A[i][j]) {
                result = max(result, recursiveLICS(A, opt, a, b) + 1);
            }
        }
        opt[i][j] = result;
        return opt[i][j];
    }
};
