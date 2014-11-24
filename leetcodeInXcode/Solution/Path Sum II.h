//
//  Path Sum II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/23/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(result, root, sum, path);;
        return result;
    }
    
    void dfs(vector<vector<int> > &result, TreeNode *node, int sum, vector<int> &path) {
        if (!node) {
            return;
        }
        
        path.push_back(node->val);
        sum -= node->val;
        
        if (!node->left && !node->right) {
            if (sum == 0) {
                result.push_back(path);
            }
        }
        
        dfs(result, node->left, sum, path);
        dfs(result, node->right, sum, path);
        
        path.pop_back();
    }
};