//
//  Majority Element II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/24/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Majority_Element_II_h
#define Majority_Element_II_h

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) return result;
        int candidate[2] = {0, 1};
        int vote[2] = {0, 0};
        for (int i : nums) {
            if (candidate[0] == i || candidate[1] == i) {
                // i is candidate
                if (candidate[0] == i) {
                    vote[0]++;
                } else {
                    vote[1]++;
                }
            } else if (vote[0] == 0 || vote[1] == 0) {
                // if there is a empty slot
                if (vote[0] == 0) {
                    candidate[0] = i;
                    vote[0] = 1;
                } else {
                    candidate[1] = i;
                    vote[1] = 1;
                }
            } else {
                vote[0]--;
                vote[1]--;
            }
        }
        if (count(nums, candidate[0]) > nums.size() / 3) result.push_back(candidate[0]);
        if (count(nums, candidate[1]) > nums.size() / 3) result.push_back(candidate[1]);
        return result;
    }
    
private:
    int count(vector<int>& nums, int target) {
        int result = 0;
        for (int i : nums) {
            if (i == target) {
                result++;
            }
        }
        return result;
    }
};

#endif /* Majority_Element_II_h */
