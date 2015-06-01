//
//  Longest Substring with At Most K Distinct Characters.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/31/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        vector<int> last(ALPHABET, -1);
        int start = 0;
        int best = 0;
        for (int i = 0; i < s.size(); i++) {
            int index = s[i];
            if (last[index] < start) {
                if (k > 0) {
                    k--;
                } else {
                    start = firstOut(last, start) + 1;
                }
            }
            best = max(best, i - start + 1);
            last[index] = i;
        }
        return best;
    }
    
    // O(ALPHABET) complexity
    int firstOut(const vector<int> &last, int start) {
        int best = INT_MAX;
        for (int i = 0; i < ALPHABET; i++) {
            if (last[i] >= start) best = min(best, last[i]);
        }
        return best;
    }
    
    static const int ALPHABET = 256;
};
