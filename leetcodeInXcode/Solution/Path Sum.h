//
//  Path Sum.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/15/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//


// Definition for binary
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // root is nullptr
        if (!root) {
            return false;
        }
        sum -= root->val;
        // non-leaf
        if (root->left || root->right) {
            return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
        }
        // leaf
        return sum == 0;
    }
};