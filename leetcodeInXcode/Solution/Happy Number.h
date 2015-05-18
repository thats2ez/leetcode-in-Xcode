//
//  Happy Number.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/18/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> occur;
        int sum = calculate(n);
        while (sum != 1 && (occur.find(sum) == occur.end())) {
            occur.insert(sum);
            sum = calculate(sum);
        }
        return sum == 1;
    }
    
    int calculate(int n) {
        int result = 0;
        while (n > 0) {
            int d = n % 10;
            result += d * d;
            n /= 10;
        }
        return result;
    }
};