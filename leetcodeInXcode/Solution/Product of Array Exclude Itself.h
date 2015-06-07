//
//  Product of Array Exclude Itself.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/7/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> result;
        long long temp = 1;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(temp);
            temp *= nums[i];
        }
        temp = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= temp;
            temp *= nums[i];
        }
        return result;
    }
};
