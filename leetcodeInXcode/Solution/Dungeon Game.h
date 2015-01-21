//
//  Dungeon Game.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 1/16/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
//    int calculateMinimumHP(vector<vector<int>> &dungeon) {
//        int n = (int)dungeon.size();
//        if (n <= 0) return 1;
//        int m = (int)dungeon[0].size();
//        if (m <= 0) return 1;
//        
//        vector<vector<int>> opt(n+1, vector<int>(m+1, INT_MAX));
//        opt[n-1][m] = 1;
//        for (int k = n + m - 2; k >= 0; k--) {
//            for (int i = min(n-1, k); i >= 0; i--) {
//                int j = k - i;
//                if (j >= m)
//                    break;
//                int min_to_end = min(opt[i][j+1], opt[i+1][j]);
//                // cout << i << ' ' << j << endl;
//                opt[i][j] = max(min_to_end - dungeon[i][j], 1);
//            }
//        }
//        return opt[0][0];
//    }
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int n = (int)dungeon.size();
        if (n <= 0) return 1;
        int m = (int)dungeon[0].size();
        if (m <= 0) return 1;
        
        vector<vector<int>> opt(n+1, vector<int>(m+1, INT_MAX));
        opt[n-1][m] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int min_to_end = min(opt[i][j+1], opt[i+1][j]);
                opt[i][j] = max(min_to_end - dungeon[i][j], 1);
            }
        }
        return opt[0][0];
    }
};