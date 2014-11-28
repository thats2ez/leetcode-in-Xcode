//
//  Best Time to Buy and Sell Stock II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/27/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i-1] > 0) {
                result += prices[i] - prices[i-1];
            }
        }
        return result;
    }
};