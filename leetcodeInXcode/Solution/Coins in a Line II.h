//
//  Coins in a Line II.h
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
        if (n == 0) return false;
        if (n < 3) return true;
        int sum = 0;
        
        vector<int> opt(n+2, 0);
        opt[n-1] = values[n-1];
        sum = opt[n-2] = values[n-2] + values[n-1];
        for (int i = n - 3; i >= 0; i--) {
            sum += values[i];
            int take_one = values[i] + min(opt[i+2], opt[i+3]);
            int take_two = values[i] + values[i+1] + min(opt[i+3], opt[i+4]);
            opt[i] = max(take_one, take_two);
        }
        return opt[0] > sum - opt[0];
    }
};
