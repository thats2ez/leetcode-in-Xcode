//
//  Evaluate Reverse Polish Notation.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/15/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                switch(tokens[i][0]) {
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(a-b);
                        break;
                    case '*':
                        s.push(a*b);
                        break;
                    case '/':
                        s.push(a/b);
                        break;
                    default:
                        ;
                }
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};