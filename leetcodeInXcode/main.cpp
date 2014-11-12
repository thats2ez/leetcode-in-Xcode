//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Sudoku Solver.h"

int main() {
    Solution s;
    vector<vector<char> > board;
    string grid[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    for (string s : grid) {
        vector<char> v;
        for (char c : s) {
            v.push_back(c);
        }
        board.push_back(v);
    }
    s.solveSudoku(board);
    return 0;
}