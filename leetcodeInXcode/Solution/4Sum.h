////
////  4Sum.h
////  leetcodeInXcode
////
////  Created by Kaiqi on 11/14/14.
////  Copyright (c) 2014 edu.self. All rights reserved.
////
//
//class Solution {
//public:
//    vector<vector<int> > fourSum(vector<int> &num, int target) {
//        vector<vector<int> > results;
//        sort(num.begin(), num.end());
//        for (int i = 0; i < num.size(); i++) {
//            if (i > 0 && num[i] == num[i-1])
//                continue;
//            for (int j = i + 1; j < num.size(); j++) {
//                if (j > i && num[j] == num[j-1])
//                    continue;
//                int k = j + 1, l = int(num.size()-1);
//                while (k < l) {
//                    int diff = num[i] + num[j] + num[k] + num[l] - target;
//                    if (diff == 0) {
//                        if (results.empty()
//                            || num[i] != results.back()[0]
//                            || num[j] != results.back()[1]
//                            || num[k] != results.back()[2]) {
//                            results.push_back(vector<int>{num[i], num[j], num[k], num[l]});
//                        }
//                        l--;
//                        k++;
//                    } else if (diff > 0) {
//                        l--;
//                    } else {
//                        k++;
//                    }
//                }
//            }
//        }
//        return results;
//    }
//};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> result;
        if (num.size() < 4) return result;
        
        sort(begin(num), end(num));
        for (int i = 0; i < num.size() - 3; i++) {
            if (i > 0 && num[i-1] == num[i]) continue;
            for (int j = i+1; j < num.size() - 2;) {
                int k = j+1, l = num.size() - 1;
                while (k < l) {
                    int sum = num[i] + num[j] + num[k] + num[l];
                    if (sum == target) {
                        result.push_back(vector<int>{num[i], num[j], num[k], num[l]});
                        do {
                            l--;
                        } while (k < l && num[l+1] == num[l]);
                    } else if (sum > target) {
                        do {
                            l--;
                        } while (k < l && num[l+1] == num[l]);
                    } else {
                        do {
                            k++;
                        } while (k < l && num[k-1] == num[k]);
                    }
                }
                while (j < num.size() - 2 && num[j+1] == num[j]) j++;
            }
        }
        return result;
    }
};