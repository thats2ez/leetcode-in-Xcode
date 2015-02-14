//
//  Search for a Range.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/14/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start = first(A, 0, n-1, target);
        if (start < 0) {
            return vector<int>{-1, -1};
        } else {
            return vector<int>{start, last(A, start, n-1, target)};
        }
    }
    
private:
    int first(int A[], int start, int end, int target) {
        if (end < start) return -1;
        int i = start, j = end;
        while (i < j) {
            int mid = i + (j-i) / 2;
            if (A[mid] >= target) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return A[i] == target ? i : -1;
    }
    
    int last(int A[], int start, int end, int target) {
        if (end < start) return -1;
        int i = start, j = end;
        while (i < j) {
            int mid = i + (j-i + 1) / 2;
            if (A[mid] > target) {
                j = mid - 1;
            } else {
                i = mid;
            }
        }
        return A[i] == target ? i : -1;
    }
};