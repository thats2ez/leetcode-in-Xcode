//
//  Maximum Subarray Difference.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/7/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        int l_max = INT_MIN, l_min = INT_MAX;
        int r_max = INT_MIN, r_min = INT_MAX;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            left[i] = sum;
            l_max = max(left[i], l_max);
            l_min = min(left[i], l_min);
        }
        
        sum = 0;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            right[i] = sum;
            r_max = max(right[i], r_max);
            r_min = min(right[i], r_min);
        }
        
        return max((l_max - r_min), (r_max, l_min));
    }
};

