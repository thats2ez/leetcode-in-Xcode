//
//  Insert Interval.h
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int before = lastLess(intervals, newInterval);
        int after = firstGreater(intervals, newInterval);
        if (before + 1 < after) {
            newInterval.start = min(intervals[before + 1].start, newInterval.start);
            newInterval.end = max(intervals[after - 1].end, newInterval.end);
            intervals.erase(intervals.begin() + before + 1, intervals.begin() + after);
        }
        intervals.insert(intervals.begin()+ before + 1, newInterval);
        return intervals;
    }
    
    int firstGreater(vector<Interval> &intervals, Interval newInterval) {
        int start = 0, end = int(intervals.size() - 1);
        int first = int(intervals.size());
        while (start <= end) {
            int mid = (start + end) / 2;
            if ( newInterval.end < intervals[mid].start) {
                first = min(mid, first);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return first;
    }
    
    int lastLess(vector<Interval> &intervals, Interval newInterval) {
        int start = 0, end = int(intervals.size() - 1);
        int last = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if ( intervals[mid].end < newInterval.start) {
                last = max(mid, last);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return last;
    }
};