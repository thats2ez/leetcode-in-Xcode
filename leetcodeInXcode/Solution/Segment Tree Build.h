//
//  Segment Tree Build.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/31/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end) return nullptr;
        SegmentTreeNode *node = new SegmentTreeNode(start, end);
        node->start = start;
        node->end = end;
        if (start == end) return node;
        int mid = start + (end - start) / 2;
        node->left = build(start, mid);
        node->right = build(mid + 1, end);
        return node;
    }
};
