//
//  Reorder List.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/16/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL) {
            return;
        }
        
        int n = 0;
        for(ListNode *cur = head; cur != NULL; cur = cur->next) {
            n++;
        }
        ListNode *a = head, *b = head;
        for(int i=0; i < (n-1)/2; i++) {
            b = b->next;
        }
        ListNode *temp = b->next;
        b->next = NULL;
        b = temp;
        
        b = reverse(b);
        
        ListNode *dummy = new ListNode(0), *pre = dummy;
        while(a != NULL || b != NULL) {
            pre->next = a;
            temp = a->next;
            a->next = b;
            a = temp;
            pre = b;
            if (b != NULL) {
                b = b->next;
            }
        }
    }
    
private:
    
    ListNode * reverse(ListNode *node) {
        ListNode *root = NULL;
        while(node != NULL) {
            ListNode *temp = node;
            node = node->next;
            temp->next = root;
            root = temp;
        }
        return root;
    }
};