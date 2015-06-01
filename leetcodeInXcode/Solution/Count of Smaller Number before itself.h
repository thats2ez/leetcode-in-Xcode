//
//  Count of Smaller Number before itself.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/1/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        int max_value = 0;
        for (int value : A) {
            max_value = max(max_value, value);
        }
        SegmentTreeNode *root = build(0, max_value);
        vector<int> count;
        count.reserve(A.size());
        for (int value : A) {
            count.push_back(query(root, 0, value-1));
            add(root, value);
        }
        return count;
    }
    
private:
    class SegmentTreeNode {
    public:
        int start, end, count;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, int count) {
            this->start = start, this->end = end;
            this->count = count;
            this->left = this->right = nullptr;
        }
    };
    
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end) return nullptr;
        SegmentTreeNode *node = new SegmentTreeNode(start, end, 0);
        node->start = start;
        node->end = end;
        if (start == end) return node;
        int mid = start + (end - start) / 2;
        node->left = build(start, mid);
        node->right = build(mid + 1, end);
        return node;
    }
    
    void add(SegmentTreeNode *root, int index) {
        // write your code here
        if (!root || index < root->start || index > root->end) return;
        root->count++;
        add(root->left, index);
        add(root->right, index);
        return;
    }
    
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root || start > root->end || end < root->start) return 0;
        if (start <= root->start && end >= root->end) return root->count;
        int left = query(root->left, start, end);
        int right = query(root->right, start, end);
        return left + right;
    }
};
