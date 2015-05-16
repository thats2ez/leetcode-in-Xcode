//
//  Sort Colors.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/17/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0, 0, 0};
        int idx[3];
        for (int i = 0; i < n; i++) {
            count[A[i]]++;
        }
        idx[0] = 0;
        idx[1] = count[0];
        idx[2] = count[0] + count[1];
        
        for (int i = 0; i < count[0]; i++) {
            if (A[i] == 0) continue;
            swap(A[idx[A[i]]++], A[i]);
            i--;
        }
        
        for (int i = count[0]; i < count[0] + count[1]; i++) {
            if (A[i] == 1) continue;
            swap(A[idx[A[i]]++], A[i]);
            i--;
        }
    }
};