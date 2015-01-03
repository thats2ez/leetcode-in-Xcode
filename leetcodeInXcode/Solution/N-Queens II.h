//
//  N-Queens II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 1/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int totalNQueens(int n) {
        // init
        this->n = n;
        horizon = vector<bool>(n, false);
        vertical = vector<bool>(n, false);
        left_diagonal = vector<bool>(2 * n - 1, false);
        right_diagonal = vector<bool>(2 * n - 1, false);
        result = 0;
        backtrack(0);
        return result;
    }
    
private:
    int n;
    vector<bool> horizon;
    vector<bool> vertical;
    vector<bool> left_diagonal;
    vector<bool> right_diagonal;
    int result;
    
    void backtrack(int i) {
        // end condition
        if (i >= n) {
            result += 1;
        }
        // try every possibility
        for (int j = 0; j < n; j++) {
            // if the grid is not valid
            if (horizon[i] || vertical[j]
                || left_diagonal[i + j]
                || right_diagonal[i + n - 1 - j])
                continue;
            horizon[i] = vertical[j] = left_diagonal[i + j] = right_diagonal[i + n - 1 - j] = true;
            backtrack(i + 1);
            horizon[i] = vertical[j] = left_diagonal[i + j] = right_diagonal[i + n - 1 - j] = false;
        }
    }
};