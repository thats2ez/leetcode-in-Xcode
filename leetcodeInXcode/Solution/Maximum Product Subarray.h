//
//  Maximum Product Subarray.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/15/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int maxProduct(int A[], int n) {
        int max_product = INT_MIN;
        int local_max = INT_MIN;
        int local_min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                max_product = max(max_product, 0);
                max_product = max(max_product, local_max);
                local_max = INT_MIN;
                local_min = INT_MAX;
            } else if (A[i] > 0) {
                local_max = local_max > 0 ? local_max * A[i] : A[i];
                local_min = local_min < 0 ? local_min * A[i] : INT_MAX;
            } else {
                max_product = max(max_product, local_max);
                int old_max = local_max;
                local_max = local_min < 0 ? local_min * A[i] : INT_MIN;
                local_min = old_max > 0 ? old_max * A[i] : A[i];
            }
        }
        max_product = max(max_product, local_max);
        return max_product < 0 ? local_min : max_product;
    }
};