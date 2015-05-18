//
//  House Robber.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/18/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        // check input
        int n = nums.size();
        if (n == 0) return 0;
        
        // init opt array
        vector<int> opt(n+1, 0);
        
        // dp
        opt[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            opt[i] = max(opt[i-1], opt[i-2] + nums[i-1]);
        }
        return opt[n];
    }
};