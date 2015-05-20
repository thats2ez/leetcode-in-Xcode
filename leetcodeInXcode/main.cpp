//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Word Search II.h"

int main() {
    Solution s;
//    vector<vector<char>> board = {{'a', 'a', 'a', 'a'},{'a', 'a', 'a', 'a'},{'a', 'a', 'a', 'a'}};
//    vector<string> words = {"aaaaaaaaaaaa","aaaaaaaaaaaaa","aaaaaaaaaaab"};
    vector<vector<char>> board = {{'a','b'},{'c','d'}};
    vector<string> words = {"cdba"};
    auto result = s.findWords(board, words);
    return 0;
}