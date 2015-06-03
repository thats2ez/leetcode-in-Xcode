//
//  Interleaving Positive and Negative Numbers.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        if (A.empty()) return;
        int pos = 0;
        for (int i : A) {
            if (i > 0) {
                pos++;
            } else {
                pos--;
            }
        }
        int i = diff(pos, A[0]) ? 0 : 1, j = i + 1;
        while (i < A.size() && j < A.size()) {
            if (i > 0 && diff(A[i], A[i-1])) {
                // A[i] is ok
                i++;
            } else if (i >= j) {
                // j need to reset
                j = i + 1;
            } else if (diff(A[i], A[j])) {
                // valid swap
                swap(A[i], A[j]);
                i += 2;
            } else {
                // not a valid swap
                j++;
            }
        }
    }
    
private:
    bool diff(int a, int b) {
        return (a > 0) != (b > 0);
    }
};
