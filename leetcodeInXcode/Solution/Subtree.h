//
//  Subtree.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/30/15.
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        // end point
        if (!T1) return !T2;
        // same from current node
        if (isSame(T1, T2)) return true;
        // subtree of T1
        return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
    
    bool isSame(TreeNode *T1, TreeNode *T2) {
        // both nullptr
        if (!T1 || !T2) return !T1 && !T2;
        // same value
        if (T1->val != T2->val) return false;
        // same subtree
        return isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
    }
};
