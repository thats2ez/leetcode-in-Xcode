//
//  House Robber II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/20/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(rob_regular(nums, 0, nums.size() - 1), rob_regular(nums, 1, nums.size()));
    }
    
private:
    int rob_regular(vector<int>& nums, int a, int b) {
        // check input
        int n = b - a;
        if (n <= 0) return 0;
        
        // init opt array
        vector<int> opt(n+1, 0);
        
        // dp
        opt[1] = nums[a];
        for (int i = 2; i <= n; i++) {
            opt[i] = max(opt[i-1], opt[i-2] + nums[a + i - 1]);
        }
        return opt[n];
    }
};