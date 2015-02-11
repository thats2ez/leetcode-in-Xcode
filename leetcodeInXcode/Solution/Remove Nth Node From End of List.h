//
//  Remove Nth Node From End of List.h
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *to_delete = slow->next;
        slow->next = slow->next->next;
        delete to_delete;
        return dummy.next;
    }
};