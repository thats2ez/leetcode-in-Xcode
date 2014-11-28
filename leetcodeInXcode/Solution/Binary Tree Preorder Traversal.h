//
//  Binary Tree Preorder Traversal.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/28/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node == nullptr) {
                continue;
            }
            result.push_back(node->val);
            s.push(node->right);
            s.push(node->left);
        }
        return result;
    }
};