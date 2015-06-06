//
//  First Bad Version.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/6/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
 */
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int i = 1, j = n;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (VersionControl::isBadVersion(mid)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return j;
    }
};

