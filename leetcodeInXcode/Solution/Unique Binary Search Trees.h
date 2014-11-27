//
//  Unique Binary Search Trees.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/27/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int numTrees(int n) {
        // edge case
        if (n == 0) {
            return 0;
        }
        // memorization
        vector<int> cache(n+1, 0);
        cache[0] = 1;
        return recursiveCount(n, cache);
    }
    
    int recursiveCount(int n, vector<int> &cache) {
        // lookup memo
        if (cache[n] > 0) {
            return cache[n];
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += recursiveCount(i, cache) * recursiveCount(n - 1 - i, cache);
        }
        //
        cache[n] = result;
        return result;
    }
};