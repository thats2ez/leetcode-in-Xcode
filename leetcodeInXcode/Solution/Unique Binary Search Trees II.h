//
//  Unique Binary Search Trees II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/27/14.
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
    vector<TreeNode *> generateTrees(int n) {
        return recursiveGenerate(n, 1);
    }
    
private:
    vector<TreeNode *> recursiveGenerate(int n, int start) {
        vector<TreeNode *> result;
        if (n == 0) {
            result.push_back(nullptr);
            return result;
        }
        for (int i = 0; i < n; i++) {
            vector<TreeNode *> leftNodes = recursiveGenerate(i, start);
            vector<TreeNode *> rightNodes = recursiveGenerate(n - i - 1, start + i + 1);
            for (int l = 0; l < leftNodes.size(); l++) {
                for (int r = 0; r < rightNodes.size(); r++) {
                    TreeNode *root = new TreeNode(start + i);
                    root->left = deepCopy(leftNodes[l]);
                    root->right = deepCopy(rightNodes[r]);
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
    TreeNode *deepCopy(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *newRoot = new TreeNode(root->val);
        newRoot->left = deepCopy(root->left);
        newRoot->right = deepCopy(root->right);
        return newRoot;
    }
};