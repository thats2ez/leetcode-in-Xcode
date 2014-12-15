//
//  Maximum Gap.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/14/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = int(num.size());
        if (n < 2)
            return 0;
        vector<int> max_bucket(n+1, -1);
        vector<int> min_bucket(n+1, -1);
        int max_i = INT_MIN;
        int min_i = INT_MAX;
        for (int i = 0; i < n; i++) {
            max_i = max(max_i, num[i]);
            min_i = min(min_i, num[i]);
        }
        if (max_i == min_i) {
            return 0;
        }
        double diff = double(max_i + 1 - min_i) / double(n+1);
        for (int i = 0; i < n; i++) {
            int b = double(num[i] - min_i) / diff;
            max_bucket[b] = max_bucket[b] < 0 ? num[i] : max(max_bucket[b], num[i]);
            min_bucket[b] = min_bucket[b] < 0 ? num[i] : min(min_bucket[b], num[i]);
        }
        int last_max = max_bucket[0];
        int max_diff = max_bucket[0] - min_bucket[0];
        for (int i = 1; i < n + 1; i++) {
            if (min_bucket[i] > 0) {
                max_diff = max(max_diff, min_bucket[i] - last_max);
                last_max = max_bucket[i];
            }
        }
        return max_diff;
    }
};