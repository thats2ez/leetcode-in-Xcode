//
//  Remove Duplicates from Sorted Array.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/11/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (i <= 0 || A[i-1] != A[j]) {
                A[i++] = A[j];
            }
        }
        return i;
    }
};