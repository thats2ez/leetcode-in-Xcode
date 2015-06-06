//
//  Binary Search Tree Iterator.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/31/14.
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
//class BSTIterator {
//public:
//    BSTIterator(TreeNode *root) {
//        push_to_next_smaller(root);
//    }
//    
//    /** @return whether we have a next smallest number */
//    bool hasNext() {
//        return !s.empty();
//    }
//    
//    /** @return the next smallest number */
//    int next() {
//        int result = s.top()->val;
//        while(!s.empty()) {
//            TreeNode *node = s.top();
//            // next node is in right sub-tree
//            if (node->right) {
//                push_to_next_smaller(node->right);
//                return result;
//            }
//            // look for next node in stack
//            s.pop();
//            while (!s.empty()) {
//                // if node = parent.left, next node is the parent
//                if (node == s.top()->left)
//                    return result;
//                // if node = parent.right, further pop stack
//                node = s.top();
//                s.pop();
//            }
//        }
//        return result;
//    }
//private:
//    stack<TreeNode *> s;
//    
//    void push_to_next_smaller(TreeNode *node) {
//        while(node != nullptr) {
//            s.push(node);
//            node = node->left;
//        }
//    }
//};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        pushLeft(root);
    }
    
    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !s.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode *node = s.top();
        s.pop();
        pushLeft(node->right);
        return node;
    }
    
private:
    stack<TreeNode *> s;
    
    void pushLeft(TreeNode *node) {
        while (node) {
            TreeNode *next = node->left;
            s.push(node);
            node = next;
        }
    }
};
