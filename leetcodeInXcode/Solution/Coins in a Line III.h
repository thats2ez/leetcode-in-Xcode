//
//  Coins in a Line III.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/30/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        int sum = 0;
        vector<vector<int>> opt(n+2, vector<int>(n+1, 0));
        for (int i = 0; i < n; i++) {
            sum += opt[i][i+1] = values[i];
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i + k <= n; i++) {
                int j = i + k;
                int take_left = values[i] + min(opt[i+2][j], opt[i+1][j-1]);
                int take_right = values[j-1] + min(opt[i+1][j-1], opt[i][j-2]);
                opt[i][j] = max(take_left, take_right);
            }
        }
        return opt[0][n] > sum - opt[0][n];
    }
};
