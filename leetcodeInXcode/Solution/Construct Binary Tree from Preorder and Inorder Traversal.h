//
//  Construct Binary Tree from Preorder and Inorder Traversal.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/19/14.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return recursiveBuild(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
private:
    TreeNode *recursiveBuild(vector<int> &preorder, int pre_b, int pre_e, vector<int> &inorder, int in_b, int in_e) {
        if (pre_b >= pre_e)
            return nullptr;
        int root_val = preorder[pre_b];
        int in_root = in_b;
        for (; in_root < in_e; in_root++) {
            if (inorder[in_root] == root_val)
                break;
        }
        int pre_left = pre_b + 1;
        int pre_right = pre_left + in_root - in_b;
        TreeNode *root = new TreeNode(root_val);
        root->left = recursiveBuild(preorder, pre_left, pre_right,
                                    inorder, in_b, in_root);
        root->right = recursiveBuild(preorder, pre_right, pre_e,
                                     inorder, in_root + 1, in_e);
        return root;
    }
};