//
//  Minimum Subarray.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/7/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if (nums.empty()) return INT_MAX;
        int sum = 0, max_before = 0;
        int best = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            best = min(best, sum - max_before);
            max_before = max(max_before, sum);
        }
        return best;
    }
};

