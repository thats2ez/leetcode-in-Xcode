//
//  Interval Sum II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/5/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /* you may need to use some attributes here */
    
    
    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        root = build(0, (int)A.size() - 1, A);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return query(root, start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        modify(root, index, value);
    }
    
private:
    class SegmentTreeNode {
    public:
        int start, end;
        long sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end) {
            this->start = start, this->end = end;
            this->sum = 0;
            this->left = this->right = nullptr;
        }
    };
    
    SegmentTreeNode * build(int start, int end, vector<int> &A) {
        // write your code here
        if (start > end) return nullptr;
        SegmentTreeNode *node = new SegmentTreeNode(start, end);
        
        if (start == end) {
            node->sum = A[start];
            return node;
        }
        
        int mid = start + (end - start) / 2;
        node->left = build(start, mid, A);
        if (node->left) node->sum += node->left->sum;
        node->right = build(mid + 1, end, A);
        if (node->right) node->sum += node->right->sum;
        return node;
    }
    
    long long query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root || start > root->end || end < root->start) return 0;
        if (start <= root->start && end >= root->end) return root->sum;
        long long left = query(root->left, start, end);
        long long right = query(root->right, start, end);
        return left + right;
    }
    
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (!root || index < root->start || index > root->end) return;
        if (root->start == root->end && root->start == index) {
            root->sum = value;
            return;
        }
        root->sum = 0;
        modify(root->left, index, value);
        if (root->left) root->sum += root->left->sum;
        modify(root->right, index, value);
        if (root->right) root->sum += root->right->sum;
    }
    
    SegmentTreeNode *root;
};

