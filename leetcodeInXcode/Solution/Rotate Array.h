//
//  Rotate Array.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/16/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n - (k % n);
        reverse(nums, 0, m);
        reverse(nums, m, n);
        reverse(nums, 0, n);
    }
    
    void reverse(vector<int>& nums, int i, int j) {
        j--;
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};