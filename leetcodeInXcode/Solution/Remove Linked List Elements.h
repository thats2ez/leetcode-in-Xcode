//
//  Remove Linked List Elements.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/18/15.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur = head;
        dummy->next = head;
        while (cur) {
            if (cur->val == val) {
                ListNode *temp = cur;
                pre->next = cur->next;
                delete cur;
            } else {
                pre = cur;
            }
            cur = pre->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};