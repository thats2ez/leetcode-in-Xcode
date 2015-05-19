//
//  Course Schedule.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/19/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // init prerequisites grid
        vector<unordered_set<int>> pre(numCourses, unordered_set<int>());
        for (auto p : prerequisites) {
            pre[p.first].insert(p.second);
        }
        
        vector<bool> visit(numCourses, false);
        vector<bool> depend(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i] && !dfs(pre, visit, depend, i)) return false;
        }
        return true;
    }
    
    bool dfs(const vector<unordered_set<int>> &pre, vector<bool> &visit, vector<bool> &depend, int i) {
        if (depend[i]) return false;
        if (visit[i]) return true;
        visit[i] = true;
        depend[i] = true;
        for (auto j : pre[i]) {
            if (!dfs(pre, visit, depend, j)) return false;
        }
        depend[i] = false;
        return true;
    }
};