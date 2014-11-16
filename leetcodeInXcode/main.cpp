//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Reorder List.h"

int main() {
    Solution s;
    ListNode a(1), b(2);
    a.next = &b;
    s.reorderList(&a);
    return 0;
}