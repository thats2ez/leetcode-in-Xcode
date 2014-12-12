//
//  Find Peak Element.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/11/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int start = 0, end = int(num.size()) - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (num[mid] > num[mid+1]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }
};