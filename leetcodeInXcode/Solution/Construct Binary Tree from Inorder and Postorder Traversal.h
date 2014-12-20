//
//  Construct Binary Tree from Inorder and Postorder Traversal.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/19/14.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return recursiveBuild(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode *recursiveBuild(vector<int> &inorder, int in_b, int in_e, vector<int> &postorder, int post_b, int post_e) {
        if (in_b >= in_e)
            return nullptr;
        int root_val = postorder[post_e - 1];
        int in_root = in_b;
        for (; in_root < in_e; in_root++) {
            if (inorder[in_root] == root_val)
                break;
        }
        int post_right = post_b + in_root - in_b;
        TreeNode *root = new TreeNode(root_val);
        root->left = recursiveBuild(inorder, in_b, in_root,
                                    postorder, post_b, post_right);
        root->right = recursiveBuild(inorder, in_root + 1, in_e,
                                     postorder, post_right, post_e - 1);
        return root;
    }
};