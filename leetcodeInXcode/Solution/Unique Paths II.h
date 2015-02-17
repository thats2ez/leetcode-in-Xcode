//
//  Unique Paths II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/16/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int n = obstacleGrid[0].size();
        vector<int> opt(n, 0);
        opt[0] = 1;
        
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] != 0) {
                    opt[j] = 0;
                } else if (j > 0) {
                    opt[j] += opt[j-1];
                }
            }
        }
        return opt[n-1];
    }
};
