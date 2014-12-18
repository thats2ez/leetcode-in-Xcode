//
//  Next Permutation.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/17/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2)
            return;
        int s = num.size() - 2;
        for (; s >= 0 && num[s] >= num[s+1]; s--)
            ;
        if (s >= 0) {
            int e = s + 1;
            for (; e < num.size() && num[s] < num[e]; e++)
                ;
            swap(num[s], num[--e]);
        }
        reverse(num.begin() + s + 1, num.end());
    }
};