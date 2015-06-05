//
//  Interval Sum.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/5/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> sum;
        long long cur = 0;
        sum.push_back(cur);
        for (int i : A) {
            cur += i;
            sum.push_back(cur);
        }
        vector<long long> result;
        for (const Interval &p : queries) {
            result.push_back(sum[p.end + 1] - sum[p.start]);
        }
        return result;
    }
};
