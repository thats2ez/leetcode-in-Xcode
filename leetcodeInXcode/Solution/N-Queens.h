//
//  N-Queens.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 1/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // init
        this->n = n;
        horizon = vector<bool>(n, false);
        vertical = vector<bool>(n, false);
        left_diagonal = vector<bool>(2 * n - 1, false);
        right_diagonal = vector<bool>(2 * n - 1, false);
        result = vector<vector<string>>();
        // empty path
        vector<string> path(n, string(n, '.'));
        backtrack(0, path);
        return result;
    }
    
private:
    int n;
    vector<bool> horizon;
    vector<bool> vertical;
    vector<bool> left_diagonal;
    vector<bool> right_diagonal;
    vector<vector<string>> result;
    
    void backtrack(int i, vector<string> &path) {
        // end condition
        if (i >= n) {
            result.push_back(path);
        }
        // try every possibility
        for (int j = 0; j < n; j++) {
            // if the grid is not valid
            if (horizon[i] || vertical[j]
                || left_diagonal[i + j]
                || right_diagonal[i + n - 1 - j])
                continue;
            path[i][j] = 'Q';
            horizon[i] = vertical[j] = left_diagonal[i + j] = right_diagonal[i + n - 1 - j] = true;
            backtrack(i + 1, path);
            path[i][j] = '.';
            horizon[i] = vertical[j] = left_diagonal[i + j] = right_diagonal[i + n - 1 - j] = false;
        }
    }
};