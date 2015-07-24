//
//  Delete Node in a Linked List.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/23/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Delete_Node_in_a_Linked_List_h
#define Delete_Node_in_a_Linked_List_h

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
    void deleteNode(ListNode* node) {
        // except for the tail
        if (!node || !node->next) return;
        
        ListNode *succ = node->next;
        node->val = succ->val;
        node->next = succ->next;
        delete succ;
    }
};

#endif /* Delete_Node_in_a_Linked_List_h */
