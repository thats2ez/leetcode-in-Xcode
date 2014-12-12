//
//  Surrounded Regions.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/11/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // impossible to surround
        if (board.size() < 3)
            return;
        if (board[0].size() < 3)
            return;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            recursiveVisit(board, i, 0);
            recursiveVisit(board, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            recursiveVisit(board, 0, j);
            recursiveVisit(board, n - 1, j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void recursiveVisit(vector<vector<char>> &board, int i, int j) {
        typedef pair<int,int> point;
        stack<point> s;
        s.push(point(i,j));
        while(!s.empty()) {
            i = s.top().first;
            j = s.top().second;
            s.pop();
            
            if (i < 0 || board.size() <= i)
                continue;
            if (j < 0 || board[i].size() <= j)
                continue;
            if (board[i][j] != 'O')
                continue;
            
            board[i][j] = 'V';
            s.push(point(i + 1, j));
            s.push(point(i - 1, j));
            s.push(point(i, j + 1));
            s.push(point(i, j - 1));
        }
    }
};