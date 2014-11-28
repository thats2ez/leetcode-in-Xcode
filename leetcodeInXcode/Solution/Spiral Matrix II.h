//
//  Spiral Matrix II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/27/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int pad = 0, num = 1;
        for (; pad < n / 2; pad++) {
            updateLevel(matrix, n, pad, num);
        }
        // only one left
        if (2 * pad + 1 == n) {
            matrix[pad][pad] = num;
        }
        return matrix;
    }
private:
    // update a ring with padding
    void updateLevel(vector<vector<int> > &matrix, int n, int pad, int &num) {
        int s = pad, l = n - 1 - pad;
        updateLine(matrix, true,  s, s, l, num);
        updateLine(matrix, false, l, s, l, num);
        updateLine(matrix, true,  l, l, s, num);
        updateLine(matrix, false, s, l, s, num);
    }
    // update a line
    void updateLine(vector<vector<int> > &matrix, bool hor, int fix, int start, int end, int &num) {
        int step = start < end ? 1 : -1;
        for(int i = start; i != end; i += step) {
            if (hor) {
                matrix[fix][i] = num++;
            } else {
                matrix[i][fix] = num++;
            }
        }
    }
};