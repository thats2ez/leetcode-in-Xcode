//
//  Clone Graph.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/25/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//


//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> clone;
        return dfsClone(node, clone);
    }
    
    UndirectedGraphNode *dfsClone(UndirectedGraphNode * node, unordered_map<int, UndirectedGraphNode *> &clone) {
        // end of graph
        if (node == nullptr) {
            return nullptr;
        }
        // if already cloned
        auto it = clone.find(node->label);
        if (it != clone.end()) {
            return it->second;
        }
        // not cloned
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        clone[newNode->label] = newNode;
        for(const auto &n : node->neighbors) {
            newNode->neighbors.push_back(dfsClone(n, clone));
        }
        return newNode;
    }
};