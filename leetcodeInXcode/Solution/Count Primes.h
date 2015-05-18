//
//  Count Primes.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/18/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        for (int i = 2; i*i < n; i++) {
            if (prime[i]) mark(prime, i);
        }
        int result = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) result++;
        }
        return result;
    }
private:
    void mark(vector<bool> &prime, int i) {
        for (int m = i + i; m < prime.size(); m += i) {
            prime[m] = false;
        }
    }
};