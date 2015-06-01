//
//  Segment Tree Modify.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/31/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (!root || index < root->start || index > root->end) return;
        // leaf
        if (root->start == root->end) {
            root->max = value;
            return;
        }
        // non-leaf
        modify(root->left, index, value);
        modify(root->right, index, value);
        root->max = max(root->left->max, root->right->max);
        return;
    }
};
