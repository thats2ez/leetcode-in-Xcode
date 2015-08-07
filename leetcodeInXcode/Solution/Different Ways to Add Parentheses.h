//
//  Different Ways to Add Parentheses.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 8/7/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Different_Ways_to_Add_Parentheses_h
#define Different_Ways_to_Add_Parentheses_h

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        istringstream in(input);
        vector<int> nums;
        vector<char> ops;
        int num = 0;
        char op = 0;
        in >> num;
        nums.push_back(num);
        while (!in.eof()) {
            in >> op;
            in >> num;
            ops.push_back(op);
            nums.push_back(num);
        }
        return recursive(nums, ops, 0, int(nums.size()));
    }
    
    vector<int> recursive(vector<int> &nums, vector<char> &ops, int i, int j) {
        // end case
        if (i + 1 >= j) {
            return vector<int>(1, nums[i]);
        }
        // split into two
        vector<int> result;
        for (int k = i; k < j - 1; k++) {
            vector<int> left = recursive(nums, ops, i, k + 1);
            vector<int> right = recursive(nums, ops, k + 1, j);
            for (int l : left) {
                for (int r : right) {
                    result.push_back(apply(ops[k], l, r));
                }
            }
        }
        return result;
    }
    
private:
    int apply(const char op, int a, int b) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            default:
                return a * b;
        }
    }
};

#endif /* Different_Ways_to_Add_Parentheses_h */
