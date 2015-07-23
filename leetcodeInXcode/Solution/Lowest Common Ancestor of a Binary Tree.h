//
//  Lowest Common Ancestor of a Binary Tree.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/23/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Lowest_Common_Ancestor_of_a_Binary_Tree_h
#define Lowest_Common_Ancestor_of_a_Binary_Tree_h

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = nullptr;
        recursiveLCA(root, p, q);
        return result;
    }
    
private:
    TreeNode* result;
    int recursiveLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        
        int l = recursiveLCA(root->left, p, q);
        if (l >= 2) return l;
        
        int r = recursiveLCA(root->right, p, q);
        if (r >= 2) return r;
        
        int m = (root == p || root == q) ? 1 : 0;
        int count = l + r + m;
        
        if (count >= 2) result = root;
        
        return count;
    }
};


#endif /* Lowest_Common_Ancestor_of_a_Binary_Tree_h */
