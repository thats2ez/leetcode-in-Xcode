//
//  Single Number II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/6/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int singleNumber(int A[], int n) {
        int m = sizeof(int) * 8;
        vector<int> times(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0, temp = A[i]; j < m; j++, temp >>= 1) {
                if (temp & 1) {
                    times[j]++;
                }
            }
        }
        int result = 0;
        for(int i = 0, mask = 1; i < m; i++, mask <<= 1) {
            if (times[i] % 3 > 0) {
                result |= mask;
            }
        }
        return result;
    }
};