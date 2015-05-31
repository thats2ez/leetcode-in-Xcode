//
//  The Smallest Difference.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/31/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if (A.empty() || B.empty()) return INT_MAX;
        int i = 0, j = 0;
        unsigned long best = labs((long)A[0] - (long)B[0]);
        
        while (i < A.size() && j < B.size()) {
            unsigned long diff = labs((long)A[i] - (long)B[j]);
            best = min(best, diff);
            if (A[i] < B[j]) {
                i++;
            } else if (A[i] > B[j]) {
                j++;
            } else {
                break;
            }
        }
        return best;
    }
};

