//
//  Trapping Rain Water.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/14/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        // search for highest bar
        int high = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > A[high]) {
                high = i;
            }
        }
        int water = 0;
        // left part
        int left_high = 0;
        for (int i = 0; i < high; i++) {
            left_high = max(left_high, A[i]);
            water += left_high - A[i];
        }
        // right part
        int right_high = 0;
        for (int i = n - 1; i > high; i--) {
            right_high = max(right_high, A[i]);
            water += right_high - A[i];
        }
        return water;
    }
};