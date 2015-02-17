//
//  Jump Game.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/16/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    bool canJump(int A[], int n) {
        int reach = 0;
        for (int i = 0; i < n; i++) {
            if (i > reach) return false;
            reach = max(reach, A[i] + i);
        }
        return true;
    }
};