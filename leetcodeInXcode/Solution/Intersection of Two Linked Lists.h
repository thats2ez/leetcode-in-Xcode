//
//  Intersection of Two Linked Lists.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/30/14.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = 0;
        for (auto p = headA; p != nullptr; p = p->next) {
            diff++;
        }
        for (auto p = headB; p != nullptr; p = p->next) {
            diff--;
        }
        while (diff > 0) {
            headA = headA->next;
            diff--;
        }
        while (diff < 0) {
            headB = headB->next;
            diff++;
        }
        while (headA != nullptr && headB != nullptr) {
            if (headA != headB) {
                headA = headA->next;
                headB = headB->next;
            } else {
                return headA;
            }
        }
        return nullptr;
    }
};