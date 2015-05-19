//
//  Reverse Linked List .h
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
    ListNode* reverseList(ListNode* head) {
        ListNode *result = nullptr;
        for (ListNode *cur = head; cur != nullptr;) {
            ListNode *temp = cur;
            cur = cur->next;
            temp->next = result;
            result = temp;
        }
        
        return result;
    }
};