//
//  Gas Station.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/15/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> income;
        int carry = 0;
        int need = 0;
        int last = -1;
        for (int i = 0; i < gas.size(); i++) {
            int cur = gas[i] - cost[i] + carry;
            carry = 0;
            if (cur > 0) {
                swap(cur, carry);
            }
            if (cur < 0) {
                last = i;
            }
            need -= cur;
            income.push_back(cur);
        }
        return carry < need ? -1 : last + 1;
    }
};