//
//  Best Time to Buy and Sell Stock III.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/28/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        vector<int> to(n, 0);
        for (int i = 1, minVal = prices[0]; i < n; i++) {
            to[i] = max(to[i-1], prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }
        vector<int> from(n, 0);
        for (int i = n - 2, maxVal = prices.back(); i >= 0; i--) {
            from[i] = max(from[i+1], maxVal - prices[i]);
            maxVal = max(maxVal, prices[i]);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, to[i] + from[i]);
        }
        return result;
    }
};