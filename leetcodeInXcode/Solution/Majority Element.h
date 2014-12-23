//
//  Majority Element.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/22/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
//    int majorityElement(vector<int> &num) {
//        unordered_map<int, int> count;
//        for (auto it = num.begin(); it != num.end(); it++) {
//            count[*it]++;
//        }
//        for (auto it = count.begin(); it != count.end(); it++) {
//            if (it->second > num.size() / 2)
//                return it->first;
//        }
//        return -1;
//    }
    int majorityElement(vector<int> &num) {
        int candidate = 0;
        int count = 0;
        for (auto it = num.begin(); it != num.end(); it++) {
            if (count == 0) {
                candidate = *it;
                count++;
            } else if (candidate == *it)
                count++;
            else
                count--;
        }
        return candidate;
    }
};