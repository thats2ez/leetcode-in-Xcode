//
//  Data Stream Median.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/5/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        priority_queue<int, vector<int>, less<int>> small;
        priority_queue<int, vector<int>, greater<int>> big;
        vector<int> result;
        for (int i : nums) {
            // insert into big half
            if (small.size() <= big.size()) {
                if (!big.empty() && i > big.top()) {
                    int j = big.top();
                    big.pop();
                    big.push(i);
                    i = j;
                }
                small.push(i);
            } else {
                if (i < small.top()) {
                    int j = small.top();
                    small.pop();
                    small.push(i);
                    i = j;
                }
                big.push(i);
            }
            result.push_back(small.top());
        }
        return result;
    }
};

