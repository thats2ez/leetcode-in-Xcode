//
//  Maximum Product Subarray.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/15/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int maxProduct(int A[], int n) {
        int max_product = INT_MIN;
        int local_max = INT_MIN;
        int local_min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                max_product = max(max_product, 0);
                max_product = max(max_product, local_max);
                local_max = INT_MIN;
                local_min = INT_MAX;
            } else if (A[i] > 0) {
                local_max = local_max > 0 ? local_max * A[i] : A[i];
                local_min = local_min < 0 ? local_min * A[i] : INT_MAX;
            } else {
                max_product = max(max_product, local_max);
                int old_max = local_max;
                local_max = local_min < 0 ? local_min * A[i] : INT_MIN;
                local_min = old_max > 0 ? old_max * A[i] : A[i];
            }
        }
        max_product = max(max_product, local_max);
        return max_product < 0 ? local_min : max_product;
    }
};

/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), best = INT_MIN, neg = INT_MAX, pos = INT_MIN;
        for (int i = 0; i < n; i++) {
            int next_neg = INT_MAX, next_pos = INT_MIN;
            if (nums[i] >= 0) {
                if (neg < 0) {
                    next_neg = neg * nums[i];
                }
                next_pos = nums[i];
                if (pos > 1) {
                    next_pos *= pos;
                }
            }
            
            if (nums[i] < 0) {
                if (neg < 0) {
                    next_pos = neg * nums[i];
                }
                next_neg = nums[i];
                if (pos > 1) {
                    next_neg *= pos;
                }
            }
            neg = next_neg;
            pos = next_pos;
            best = max(best, pos);
        }
        return best >= 0 ? best : neg;
    }
};

*/