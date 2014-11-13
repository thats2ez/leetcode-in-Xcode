//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Min Stack.h"

int main() {
//    Solution s;
    MinStack s;
    s.push(2147483646);
    s.push(2147483646);
    s.push(2147483647),
    cout << s.top() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    s.push(2147483647);
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    s.push(-2147483648);
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}