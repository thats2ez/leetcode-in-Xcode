//
//  3Sum Closest.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/9/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) {
            return 0;
        }
        sort(begin(num), end(num));
        int closest = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i-1] == num[i]) continue;
            int j = i + 1, k = num.size() - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    closest = target - sum < abs(closest - target) ? sum : closest;
                    do {
                        j++;
                    } while (j < k && num[j-1] == num[j]);
                } else if (target < sum) {
                    closest = sum - target < abs(closest - target) ? sum : closest;
                    do {
                        k--;
                    } while (j < k && num[k+1] == num[k]);
                }
            }
        }
        return closest;
    }
};