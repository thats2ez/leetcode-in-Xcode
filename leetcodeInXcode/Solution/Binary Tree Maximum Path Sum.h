//
//  Binary Tree Maximum Path Sum.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/30.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }
    
    int max3( int a, int b, int c ) {
        return max(max(a, b), c);
    }
    
    /// return max single path sum
    int dfs(TreeNode *node, int &max_length) {
        if (node) {
            // recursive
            int left = dfs(node->left, max_length);
            int right = dfs(node->right, max_length);
            
            // calculate max path with current node as root
            int path = node->val;
            if (left > 0) path += left;
            if (right > 0) path += right;
            
            // compare & set
            max_length = max(max_length, path);
            
            return  max3(left, right, 0) + node->val;
        }
        return 0;
    }
};