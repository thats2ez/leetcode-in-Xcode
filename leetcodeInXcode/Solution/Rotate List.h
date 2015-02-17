//
//  Rotate List.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/16/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//class Solution {
//public:
//    ListNode *rotateRight(ListNode *head, int k) {
//        int len = 0;
//        for (ListNode *cur = head; cur != nullptr; cur = cur->next, len++);
//        if (len == 0) return head;
//        
//        k = k % len;
//        
//        if (k == 0) return head;
//        
//        ListNode dummy(0);
//        dummy.next = head;
//        ListNode *fast = &dummy, *slow = fast;
//        for (int i = 0; i < k; i++) {
//            fast = fast->next;
//        }
//        
//        while (fast->next) {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        
//        swap(dummy.next, slow->next);
//        swap(fast->next, slow->next);
//        return dummy.next;
//    }
//};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode *tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        k = len - (k % len);
        tail->next = head;
        for (int i = 0; i < k; i++, tail = tail->next);
        head = nullptr;
        swap(head, tail->next);
        return head;
    }
};