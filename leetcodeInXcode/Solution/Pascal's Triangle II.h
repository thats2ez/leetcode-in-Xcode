//
//  Pascal's Triangle II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/15/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result{1};
        result.reserve(rowIndex + 1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = (i-1)/2; j > 0; j--) {
                result[j] = result[j-1] + result[j];
                result[i-j] = result[j];
            }
            result.push_back(1);
            if (i % 2 == 0) {
                result[i/2] *= 2;
            }
        }
        return result;
    }
};