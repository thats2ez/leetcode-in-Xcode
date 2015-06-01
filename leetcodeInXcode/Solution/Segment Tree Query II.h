//
//  Segment Tree Query II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/31/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root || start > root->end || end < root->start) return 0;
        if (start <= root->start && end >= root->end) return root->count;
        int left = query(root->left, start, end);
        int right = query(root->right, start, end);
        return left + right;
    }
};
