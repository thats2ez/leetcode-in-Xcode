//
//  Invert Binary Tree.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/24/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Invert_Binary_Tree_h
#define Invert_Binary_Tree_h

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

#endif /* Invert_Binary_Tree_h */
