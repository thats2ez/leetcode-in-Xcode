//
//  Merge Two Sorted Lists.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/10/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *to_attach;
            if (l1->val < l2->val) {
                to_attach = l1;
                l1 = l1->next;
            } else {
                to_attach = l2;
                l2 = l2->next;
            }
            pre->next = to_attach;
            pre = pre->next;
        }
        
        if (l1 != nullptr) {
            pre->next = l1;
        } else {
            pre->next = l2;
        }
        
        return dummy.next;
    }
};