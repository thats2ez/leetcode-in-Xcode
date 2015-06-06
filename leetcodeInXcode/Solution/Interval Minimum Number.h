//
//  Interval Minimum Number.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/5/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        root = build(0, A.size() - 1, A);
        vector<int> result;
        for (Interval i : queries) {
            result.push_back(query(root, i.start, i.end));
        }
        return result;
    }
    
private:
    class SegmentTreeNode {
    public:
        int start, end, min;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end) {
            this->start = start, this->end = end;
            this->min = INT_MAX;
            this->left = this->right = nullptr;
        }
    };
    
    SegmentTreeNode * build(int start, int end, vector<int> &A) {
        // write your code here
        if (start > end) return nullptr;
        SegmentTreeNode *node = new SegmentTreeNode(start, end);
        
        if (start == end) {
            node->min = A[start];
            return node;
        }
        
        int mid = start + (end - start) / 2;
        node->left = build(start, mid, A);
        if (node->left) node->min = min(node->min, node->left->min);
        node->right = build(mid + 1, end, A);
        if (node->right) node->min = min(node->min, node->right->min);
        return node;
    }
    
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root || start > root->end || end < root->start) return INT_MAX;
        if (start <= root->start && end >= root->end) return root->min;
        int left = query(root->left, start, end);
        int right = query(root->right, start, end);
        return min(left, right);
    }
    
    SegmentTreeNode *root;
};
