//
//  Number of Islands.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/18/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        
        int result;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result += recursiveCount(grid, visited, i, j, n, m);
            }
        }
        return result;
    }
    
    int recursiveCount(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j, int n, int m) {
        // outside the board
        if (i < 0 || i >= n || j < 0 || j >= m) return 0;
        
        // visited point
        if (visited[i][j]) return 0;
        visited[i][j] = true;
        
        // water
        if (grid[i][j] == '0') return 0;
        
        // if land, recursively visit neighbours
        recursiveCount(grid, visited, i - 1, j, n, m);
        recursiveCount(grid, visited, i + 1, j, n, m);
        recursiveCount(grid, visited, i, j - 1, n, m);
        recursiveCount(grid, visited, i, j + 1, n, m);
        return 1;
    }
};