//
//  Kth Smallest Element in a BST.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/23/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Kth_Smallest_Element_in_a_BST_h
#define Kth_Smallest_Element_in_a_BST_h

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
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        int target = INT_MIN;
        recursive(root, count, target);
        return target;
    }
    
    void recursive(TreeNode *root, int &count, int &target) {
        // end or found
        if (!root || target > INT_MIN) return;
        // left
        recursive(root->left, count, target);
        // mid
        if(--count == 0) target = root->val;
        // right
        recursive(root->right, count, target);
        return;
    }
};

#endif /* Kth_Smallest_Element_in_a_BST_h */
