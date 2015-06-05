//
//  Minimum Adjustment Cost.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/4/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        if (A.empty()) return 0;
        double sum = (double)accumulate(A.begin(), A.end(), 0);
        double avg = sum / A.size();
        int top = (int)(avg + (double)target / 2 + 0.5);
        int bottom = (int)(avg - (double)target / 2 + 0.5);
        
        int result = 0;
        for (int i : A) {
            if (i < bottom) {
                result += (bottom - i);
            } else if (i > top) {
                result += (i - top);
            }
        }
        
        return result;
    }
};
