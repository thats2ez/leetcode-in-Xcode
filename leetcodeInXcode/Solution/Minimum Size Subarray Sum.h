//
//  Minimum Size Subarray Sum.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/19/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = -1, sum = 0, n = nums.size();
        int result = INT_MAX;
        while (j < n) {
            if (sum >= s) {
                result = min(result, j - i + 1);
                sum -= nums[i++];
            } else if (++j < n) {
                sum += nums[j];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};