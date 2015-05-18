//
//  Binary Tree Right Side View.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/18/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        recursiveView(result, root, 0);
        
        return result;
    }
    
    void recursiveView(vector<int> &result, TreeNode* node, int level) {
        // end point
        if (!node) return;
        
        // if is rightmost
        if (level >= result.size()) result.push_back(node->val);
        
        // go deeper
        recursiveView(result, node->right, level+1);
        recursiveView(result, node->left, level+1);
    }
};