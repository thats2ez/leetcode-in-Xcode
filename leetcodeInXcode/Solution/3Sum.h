//
//  3Sum.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/13/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > results;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i-1])
                continue;
            int j = i + 1, k = int(num.size()-1);
            while (j < k) {
                int diff = num[j] + num[k] + num[i];
                if (diff == 0) {
                    if (results.empty()
                        || num[i] != results.back()[0]
                        || num[j] != results.back()[1]) {
                        results.push_back(vector<int>{num[i], num[j], num[k]});
                    }
                    k--;
                    j++;
                } else if (diff > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return results;
    }
};