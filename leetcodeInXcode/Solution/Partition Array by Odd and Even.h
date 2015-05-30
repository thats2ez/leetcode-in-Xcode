//
//  Partition Array by Odd and Even.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/30/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    // this is WRONG, this is stable partition
    void partitionArray(vector<int> &nums) {
        // write your code here
        int i = 0;
        while (i < nums.size() && (nums[i] % 2)) {
            i++;
        }
        int j = i + 1;
        while (j < nums.size()) {
            if (nums[j] % 2) {
                swap(nums[i++], nums[j++]);
            } else {
                j++;
            }
        }
    }
    
    void partitionArray(vector<int> &nums) {
        // write your code here
        int i = 0, j = nums.size() - 1;
        
        while (i < j) {
            if (nums[i] % 2) {
                i++;
            } else if (!(nums[j] % 2)) {
                j--;
            } else {
                swap(nums[i++], nums[j--]);
            }
        }
    }
};
