//
//  Search Insert Position.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/14/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0) return 0;
        int i = 0, j = n - 1;
        while (i < j) {
            int mid = i + (j-i) / 2;
            if (A[mid] >= target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return A[i] >= target ? i : i + 1;
    }
};