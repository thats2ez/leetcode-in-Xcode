//
//  Count and Say.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/17/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    string countAndSay(int n) {
        string cur("1");
        for (int i = 1; i < n; i++) {
            string next;
            int j = 0;
            while(j < cur.length()) {
                int k = 1;
                while (j+k < cur.length() && cur[j] == cur[j+k]) {
                    k++;
                }
                next = next + to_string(k) + cur[j];
                j += k;
            }
            cur = next;
        }
        return cur;
    }
};