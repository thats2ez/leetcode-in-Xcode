//
//  Insertion Sort List.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/17/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    static bool myLess(ListNode *a, ListNode *b) {
        return a->val < b->val;
    }
public:
    ListNode *insertionSortList(ListNode *head) {
        vector<ListNode> v;
        for (ListNode *node = head; node != nullptr; node = node->next) {
            v.push_back(node);
        }
        for (int )
    }
};