//
//  Rehashing.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/3/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int capacity = 2 * hashTable.size();
        vector<ListNode *> result(capacity, nullptr);
        for (int i = 0; i < hashTable.size(); i++) {
            ListNode *node = hashTable[i];
            while (node) {
                int index = node->val % capacity;
                if (index < 0) index += capacity;
                ListNode *temp = node->next;
                node->next = result[index];
                result[index] = node;
                node = temp;
            }
        }
        for (int i = 0; i < result.size(); i++) {
            result[i] = reverse(result[i]);
        }
        return result;
    }
    
private:
    ListNode * reverse(ListNode *node) {
        ListNode *result = nullptr;
        while (node) {
            ListNode *temp = node->next;
            node->next = result;
            result = node;
            node = temp;
        }
        return result;
    }
};

