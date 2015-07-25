//
//  Summary Ranges.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/24/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Summary_Ranges_h
#define Summary_Ranges_h

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        int start = nums[0];
        int expect = start + 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == expect) {
                expect++;
            } else {
                result.push_back(range(start, expect - 1));
                start = nums[i];
                expect = start + 1;
            }
        }
        result.push_back(range(start, expect - 1));
        return result;
    }
    
private:
    string range(int start, int end) {
        if (start == end) {
            return to_string(start);
        } else {
            return to_string(start) + "->" + to_string(end);
        }
    }
};

#endif /* Summary_Ranges_h */
