//
//  The Skyline Problem.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 8/17/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef The_Skyline_Problem_h
#define The_Skyline_Problem_h


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        if (buildings.empty()) return result;
        
        map<int, vector<int>> corners;
        for (int i = 0; i < buildings.size(); i++) {
            vector<int> b = buildings[i];
            int li = b[0], ri = b[1];
            corners[li].push_back(i);
            corners[ri].push_back(i);
        }
        
        int pre_x = -1, pre_y = -1;
        map<int, unordered_set<int>> roof;
        for (auto it = corners.begin(); it != corners.end(); it++) {
            int x = it->first;
            for (int i : it->second) {
                int hi = buildings[i][2];
                if (x == buildings[i][0]) {
                    // x == li
                    roof[hi].insert(i);
                } else {
                    // x == ri
                    roof[hi].erase(i);
                    if (roof[hi].empty()) {
                        roof.erase(hi);
                    }
                }
            }
            
            int y = roof.empty() ? 0 : roof.rbegin()->first;
            if (y != pre_y) {
                if (pre_x >= 0) {
                    result.push_back(make_pair(pre_x, pre_y));
                }
                pre_x = x, pre_y = y;
            }
        }
        result.push_back(make_pair(pre_x, pre_y));
        return result;
    }
};

#endif /* The_Skyline_Problem_h */
