//
//  Insert Node in a Binary Search Tree.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/5/15.
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (!root) return node;
        if (node->val < root->val) {
            if (root->left) {
                insertNode(root->left, node);
            } else {
                root->left = node;
            }
        } else {
            if (root->right) {
                insertNode(root->right, node);
            } else {
                root->right = node;
            }
        }
        return root;
    }
};

