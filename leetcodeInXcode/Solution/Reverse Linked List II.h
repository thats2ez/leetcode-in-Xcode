//
//  Reverse Linked List II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/6/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur, *end;
        n -= m--;
        while(m > 0) {
            pre = pre->next;
            m--;
        }
        end = pre->next;
        cur = end->next;
        while(n > 0) {
            end->next = cur;
            cur = cur->next;
            end->next->next = pre->next;
            pre->next = end->next;
            n--;
        }
        end->next = cur;
        return dummy->next;
    }
};