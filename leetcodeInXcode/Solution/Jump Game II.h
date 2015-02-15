//
//  Jump Game II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/14/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int jump(int A[], int n) {
        int cur = 0;
        int next = 0;
        int jump = 0;
        for (int i = 0; cur < n - 1; i++) {
            if (i > cur) {
                if (i > next) return -1;
                cur = next;
                jump++;
            }
            next = max(next, i + A[i]);
        }
        return jump;
    }
};