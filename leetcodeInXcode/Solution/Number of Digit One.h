//
//  Number of Digit One.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/7/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int countDigitOne(int n) {
//        cout << n << endl;
        if (n <= 0) return 0;
        long long a = 0;
        long long base = 1;
        while (base * 10 <= n) {
            a = base + a * 10;
            base *= 10;
        }
        int remain = n % base;
        int result = (int)a * (n / base) + countDigitOne(remain) + (int)min(base, n - base + 1);
        return result;
    }
};