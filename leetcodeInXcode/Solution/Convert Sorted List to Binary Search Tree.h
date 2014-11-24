//
//  Convert Sorted List to Binary Search Tree.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/23/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
            n++;
        }
        return dfs(0, head, n);
    }
    
    TreeNode *dfs(int i, ListNode *&next, int n) {
        if (i >= n) {
            return nullptr;
        }
        
        TreeNode *left = dfs(2 * i + 1, next, n);
        TreeNode *node = new TreeNode(next->val);
        next = next->next;
        TreeNode *right = dfs(2 * i + 2, next, n);
        node->left = left;
        node->right = right;
        
        return node;
    }
};