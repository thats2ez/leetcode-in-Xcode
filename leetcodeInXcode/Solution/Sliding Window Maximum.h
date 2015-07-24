//
//  Sliding Window Maximum.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/23/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Sliding_Window_Maximum_h
#define Sliding_Window_Maximum_h

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty() || k <= 0 || k > nums.size()) return result;
        vector<int> s;
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            // no lower value in stack
            if (s.empty() || nums[i] < nums[s.back()]) {
                s.push_back(i);
            } else {
                // pop lower values in stack
                while (!s.empty() && nums[s.back()] <= nums[i]) {
                    s.pop_back();
                }
                // index of largest in stack before moving window
                m = min(m, int(s.size()));
                s.push_back(i);
            }
            // move window by 1, update index
            if (s[m] + k - 1 < i) {
                m++;
            }
            if (i >= k - 1) result.push_back(nums[s[m]]);
        }
        return result;
    }
};

#endif /* Sliding_Window_Maximum_h */
