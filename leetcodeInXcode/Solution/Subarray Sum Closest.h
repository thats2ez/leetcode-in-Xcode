//
//  Subarray Sum Closest.h
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
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        int cur = 0;
        vector<pair<int, int>> sum;
        sum.push_back(make_pair(cur, -1));
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            sum.push_back(make_pair(cur, i));
        }
        sort(sum.begin(), sum.end());
        int best = INT_MAX;
        vector<int> result{0,0};
        for (int i = 1; i < sum.size(); i++) {
            int diff = sum[i].first - sum[i-1].first;
            if (best > diff) {
                best = diff;
                result[0] = sum[i-1].second;
                result[1] = sum[i].second;
                if (result[0] > result[1]) swap(result[0], result[1]);
                result[0]++;
            }
        }
        return result;
    }
};

