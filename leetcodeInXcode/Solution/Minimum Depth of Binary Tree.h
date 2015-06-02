//
//  Minimum Depth of Binary Tree.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int depth = 1;
        if (!root->left || !root->right) {
            depth += max(minDepth(root->left), minDepth(root->right));
        } else {
            depth += min(minDepth(root->left), minDepth(root->right));
        }
        return depth;
    }
};
