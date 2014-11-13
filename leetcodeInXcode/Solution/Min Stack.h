//
//  Min Stack.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/12/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class MinStack {
public:
    void push(int x) {
        s.push(s.empty() ? 0 : (x xor minV));
        p.push_back(x < minV || s.empty());
        minV = min(minV, x);
    }
    
    void pop() {
        if (s.empty())
            return;
        if(p.back())
            minV = minV xor s.top();
        p.pop_back();
        s.pop();
        if (s.empty())
            minV = INT_MAX;
    }
    
    int top() {
        return p.back() ? minV : (s.top() xor minV);
    }
    
    int getMin() {
        return minV;
    }
private:
    stack<int> s;
    vector<bool> p;
    int minV = INT_MAX;
};