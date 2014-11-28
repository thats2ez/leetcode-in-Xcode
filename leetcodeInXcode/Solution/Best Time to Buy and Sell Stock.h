//
//  Best Time to Buy and Sell Stock.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/27/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minVal = INT_MAX;
        int best = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (minVal != INT_MAX && prices[i] - minVal > best) {
                best = prices[i] - minVal;
            }
            minVal = min(minVal, prices[i]);
        }
        return best;
    }
};