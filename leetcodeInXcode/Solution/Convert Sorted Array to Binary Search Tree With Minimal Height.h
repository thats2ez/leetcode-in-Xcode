//
//  Convert Sorted Array to Binary Search Tree With Minimal Height.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/1/15.
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return recursiveBuild(A, 0, (int)A.size() - 1);
    }
    
private:
    TreeNode * recursiveBuild(const vector<int> &A, int i, int j) {
        if (i > j) return nullptr;
        int mid = i + (j - i) / 2;
        TreeNode *node = new TreeNode(A[mid]);
        node->left = recursiveBuild(A, i, mid - 1);
        node->right = recursiveBuild(A, mid + 1, j);
        return node;
    }
};

