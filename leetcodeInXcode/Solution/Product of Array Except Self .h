//
//  Product of Array Except Self .h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/23/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Product_of_Array_Except_Self__h
#define Product_of_Array_Except_Self__h

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left = {1};
        vector<int> right = {1};
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            left.push_back(nums[i] * left.back());
        }
        for (int i = n - 1; i > 0; i--) {
            right.push_back(nums[i] * right.back());
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(left[i] * right[n - 1 - i]);
        }
        return result;
    }
};

#endif /* Product_of_Array_Except_Self__h */
