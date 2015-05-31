//
//  Triangle Count.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/30/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int result = 0;
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); i++) {
            int k = 0;
            for (int j = i + 1; j < S.size(); j++) {
                k = max(k, j+1);
                int valid = k - j - 1;
                while (k < S.size() && (S[i] + S[j] > S[k])) {
                    valid++;
                    k++;
                }
                result += valid;
            }
        }
        return result;
    }
};

