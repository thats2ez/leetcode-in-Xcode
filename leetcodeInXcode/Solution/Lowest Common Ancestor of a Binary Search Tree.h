//
//  Lowest Common Ancestor of a Binary Search Tree.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/11/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Lowest_Common_Ancestor_of_a_Binary_Search_Tree_h
#define Lowest_Common_Ancestor_of_a_Binary_Search_Tree_h

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
        if (!root || !p || !q) return nullptr;
        
        int a = p->val, b = q->val;
        if (p->val > q->val) {
            swap(a, b);
        }
        if ((a <= root->val) && (root->val <= b)) {
            return root;
        } else if (a > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else { // b < root->val
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};

#endif /* Lowest_Common_Ancestor_of_a_Binary_Search_Tree_h */
