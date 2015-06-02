//
//  Route Between Two Nodes in Graph.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//


// Definition for Directed graph.
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};
 
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        if (s == t) return true;
        unordered_set<DirectedGraphNode*> visit;
        stack<DirectedGraphNode*> frontier;
        frontier.push(s);
        visit.insert(s);
        while (!frontier.empty()) {
            auto node = frontier.top();
            frontier.pop();
            for (auto neighbor : node->neighbors) {
                if (visit.find(neighbor) != visit.end()) continue;
                if (neighbor == t) return true;
                frontier.push(neighbor);
                visit.insert(neighbor);
            }
        }
        return false;
    }
};


