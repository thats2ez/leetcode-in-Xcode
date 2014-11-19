//
//  Container With Most Water.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/18/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int maxArea(vector<int> &height) {
        // edge case
        int result = 0, i = 0, j = int(height.size()) - 1;
        while (i < j) {
            int temp;
            result = max(result, min(height[i], height[j]) * (j-i));
            if (height[i] < height[j]) {
                for (temp = i + 1; temp < height.size() && height[temp] <= height[i]; temp++) {
                    ;
                }
                i = temp;
            } else {
                for (temp = j - 1; temp >= 0 && height[temp] <= height[j]; temp--) {
                    ;
                }
                j = temp;
            }
        }
        return result;
    }
};