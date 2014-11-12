//
//  Sudoku Solver.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/11/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
//    void solveSudoku(vector<vector<char> > &board) {
//        vector<unordered_set<char> >
//        h = vector<unordered_set<char> >(9, unordered_set<char>({'1','2','3','4','5','6','7','8','9'})),
//        v = vector<unordered_set<char> >(9, unordered_set<char>({'1','2','3','4','5','6','7','8','9'})),
//        g = vector<unordered_set<char> >(9, unordered_set<char>({'1','2','3','4','5','6','7','8','9'}));
//        for(int i=0; i < 9; i++){
//            for(int j=0; j < 9; j++){
//                auto it = h[i].find(board[i][j]);
//                if(it != h[i].end())
//                    h[i].erase(it);
//                it = v[j].find(board[i][j]);
//                if(it != v[j].end())
//                    v[j].erase(it);
//                int k = (i / 3) * 3 + (j % 3);
//                it = g[k].find(board[i][j]);
//                if(it != g[k].end())
//                    g[k].erase(it);
//            }
//        }
//        dfs(board, h, v, g, 0);
//    }
//    
//private:
//    bool dfs(vector<vector<char> > &board, vector<unordered_set<char> > &h, vector<unordered_set<char> > &v, vector<unordered_set<char> > &g, int p) {
//        if (p >= 9 * 9)
//            return true;
//        int i = p / 9, j = p % 9, k = (i / 3) * 3 + (j % 3);
//        if (board[i][j] != '.')
//            return dfs(board, h, v, g, p+1);
//        unordered_set<char> *s;
//        if (h[i].size() < v[j].size())
//            s = h[i].size() < g[k].size() ? &h[i] : &g[k];
//        else
//            s = v[j].size() < g[k].size() ? &v[j] : &g[k];
//        for(char c : *s) {
//            auto it_h = h[i].find(c);
//            auto it_v = v[j].find(c);
//            auto it_g = g[k].find(c);
//            if (it_h != h[i].end() && it_v != v[j].end() && it_g != g[k].end()) {
//                h[i].erase(it_h);
//                v[j].erase(it_v);
//                g[k].erase(it_g);
//                if (dfs(board, h, v, g, p+1)) {
//                    board[i][j] = c;
//                    return true;
//                }
//                h[i].insert(c);
//                v[j].insert(c);
//                g[k].insert(c);
//            }
//        }
//        return false;
//    }
    bool solveSudoku(vector<vector<char> > &board) {
        for (int i=0; i < 9; i++) {
            for (int j=0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k=0; k < 9; k++) {
                        board[i][j] = '1' + k;
                        if (isValid(board, i, j) && solveSudoku(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
private:
    bool isValid(vector<vector<char> > &board, int i, int j) {
        int r = (i / 3) * 3;
        int c = (j / 3) * 3;
        for (int m=0; m < 9; m++) {
            if ((board[i][j] == board[m][j] && i != m) ||
                (board[i][j] == board[i][m] && j != m)) {
                return false;
            }
            if (board[i][j] == board[r+m/3][c+m%3] && (i != r+m/3 || j != c+m%3)) {
                return false;
            }
        }
        return true;
    }
};