//
//  Subarray Sum.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int cur = 0;
        vector<int> result = {-1, -1};
        unordered_map<int, int> sum;
        sum[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (sum.find(cur) != sum.end()) {
                result[0] = min(sum[cur], i) + 1;
                result[1] = max(sum[cur], i);
            }
            sum[cur] = i;
        }
        return result;
    }
};
