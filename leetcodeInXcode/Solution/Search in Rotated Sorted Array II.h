//
//  Search in Rotated Sorted Array II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/17/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    bool search(int A[], int n, int target) {
        int pivot = search_pivot(A, n);
        if (pivot < 0) {
            return binary_search(A, 0, n - 1, target) >= 0;
        } else if (A[0] <= target) {
            return binary_search(A, 0, pivot - 1, target) >= 0;
        } else {
            return binary_search(A, pivot, n - 1, target) >= 0;
        }
    }
private:
    int search_pivot(int A[], int n) {
        int i = 0, j = n-1;
        if (j <= 0 || A[i] <= A[j]) return -1;
        while (i < j - 1) {
            int mid = i + (j-i)/2;
            if (A[mid] > A[j]) {
                i = mid;
            } else if (A[i] > A[mid]) {
                j = mid;
            } else {
                return -1;
            }
        }
        return j;
    }
    
    int binary_search(int A[], int start, int end, int target) {
        int i = start, j = end;
        while (i <= j) {
            int mid = i + (j-i) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > target) {
                j = mid - 1;
            } else if (A[mid] < target) {
                i = mid + 1;
            }
        }
        return -1;
    }
};