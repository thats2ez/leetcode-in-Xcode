//
//  Merge Intervals.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/9/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    struct cmp {
        bool operator()(Interval a, Interval b) {
            return a.start > b.start;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() == 0)
            return intervals;
        priority_queue<Interval, vector<Interval>, cmp> q(intervals.begin(), intervals.end());
        vector<Interval> result;
        Interval cur = q.top();
        q.pop();
        while (!q.empty()) {
            Interval next = q.top();
            q.pop();
            if (next.start <= cur.end) {
                cur.end = max(next.end, cur.end);
            } else {
                result.push_back(cur);
                cur = next;
            }
        }
        result.push_back(cur);
        return result;
    }
};