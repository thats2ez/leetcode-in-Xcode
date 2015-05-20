//
//  Course Schedule II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/19/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // init graph
        vector<unordered_set<int>> out_d(numCourses, unordered_set<int>()), in_d(numCourses, unordered_set<int>());
        for (auto p : prerequisites) {
            out_d[p.second].insert(p.first);
            in_d[p.first].insert(p.second);
        }
        
        vector<int> output;
        
        // node with no in-degree
        stack<int> pending;
        for (int i = 0; i < in_d.size(); i++) {
            if (in_d[i].empty()) {
                pending.push(i);
            }
        }
        
        while (!pending.empty()) {
            int i = pending.top();
            pending.pop();
            output.push_back(i);
            
            for (int j : out_d[i]) {
                in_d[j].erase(i);
                if (in_d[j].empty()) {
                    pending.push(j);
                }
            }
        }
        
        return output.size() == numCourses ? output : vector<int>();
    }
};