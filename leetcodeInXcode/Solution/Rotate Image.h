//
//  Rotate Image.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/28/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int pad = 0; pad < n / 2; pad++) {
            int end = n - 1 - pad;
            for (int i = 0; i + pad < end; i++) {
                int temp = matrix[pad][pad + i];
                matrix[pad][pad + i] = matrix[end - i][pad];
                matrix[end - i][pad] = matrix[end][end - i];
                matrix[end][end - i] = matrix[pad + i][end];
                matrix[pad + i][end] = temp;
            }
        }
    }
};