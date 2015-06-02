//
//  Delete Digits.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        if (k <= 0) return A;
        priority_queue<pair<int, int>> big;
        int last = 0;
        for (int i = (int)A.size() - 1; i >= 0; i--) {
            int val = last - A[i];
            last = A[i];
            if (val > 0) {
                val = (int)A.size() - i;
            } else if (val < 0) {
                val = i - (int)A.size();
            }
            if (big.size() < k) {
                big.push(pair<int, int>(val, i));
            } else if (big.top().first > val) {
                big.pop();
                big.push(pair<int, int>(val, i));
            }
        }
        unordered_set<int> del;
        while (!big.empty()) {
            del.insert(big.top().second);
            big.pop();
        }
        string result = "";
        for (int i = 0; i < A.size(); i++) {
            if (del.find(i) == del.end())
                result += A[i];
        }
        return result;
    }
};

