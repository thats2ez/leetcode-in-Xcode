//
//  Longest Increasing Continuous subsequence.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/30/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        if (A.size() == 1) return 1;
        int asc = 1, desc = 1;
        int asc_best = 0, desc_best = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) {
                asc_best = max(asc_best, ++asc);
                desc = 1;
            } else if (A[i] < A[i-1]) {
                asc = 1;
                desc_best = max(desc_best, ++desc);
            } else {
                asc = 1;
                desc = 1;
            }
        }
        return max(asc_best, desc_best);
    }
};
