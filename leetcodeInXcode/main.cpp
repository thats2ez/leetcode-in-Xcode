//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Rotate List.h"

int main() {
    Solution s;
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    auto result = s.rotateRight(&head, 2);
    return 0;
}