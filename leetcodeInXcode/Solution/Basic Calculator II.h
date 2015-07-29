//
//  Basic Calculator II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/28/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Basic_Calculator_II_h
#define Basic_Calculator_II_h

class Solution {
public:
    int calculate(string s) {
        vector<int> num;
        vector<char> op;
        
        // read in characters and op
        // apply * and / on the fly
        int i = 0;
        int n = readNum(s, i);
        num.push_back(n);
        while (i < s.length()) {
            char c = readOp(s, i);
            if (!c) break;
            int next = readNum(s, i);
            if ( c == '+' || c == '-') {
                op.push_back(c);
                num.push_back(next);
            } else if (c == '/' || c == '*') {
                int last = num.back();
                num.pop_back();
                int result = apply(c, last, next);
                num.push_back(result);
            }
        }
        
        // read again and apply remaining ops
        int result = num[0];
        i = 1;
        for (char c : op) {
            result = apply(c, result, num[i++]);
        }
        return result;
    }
    
private:
    int apply(char op, int a, int b) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '/':
                return a / b;
            case '*':
                return a * b;
            default:
                return 0;
        }
    }
    
    int readNum(const string &s, int &begin) {
        skipSpaces(s, begin);
        int end = begin;
        while (end < s.length() && s[end] >= '0' && s[end] <= '9') {
            end++;
        }
        string sub = s.substr(begin, end - begin);
        begin = end;
        return stoi(sub);
    }
    
    int readOp(const string &s, int &i) {
        skipSpaces(s, i);
        if (i < s.length()) {
            return s[i++];
        } else {
            return 0;
        }
    }
    
    void skipSpaces(const string &s, int &i) {
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
    }
};

#endif /* Basic_Calculator_II_h */
