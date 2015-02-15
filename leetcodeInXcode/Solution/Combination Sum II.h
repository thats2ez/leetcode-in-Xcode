//
//  Combination Sum II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/25/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

//class Solution {
//public:
//    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
//        vector<vector<int> > result;
//        vector<int> path;
//        sort(num.begin(), num.end());
//        recursiveSum(num, result, path, 0, target);
//        return result;
//    }
//    
//    void recursiveSum(vector<int> &num, vector<vector<int> > &result, vector<int> &path, int valid, int remaining) {
//        // valid combinatioj
//        if (remaining == 0 && !path.empty()) {
//            result.push_back(path);
//        }
//        
//        for (int i = valid; i < num.size(); i++) {
//            // stop here, impossible to get result in valid candidates
//            if (remaining < num[i]) {
//                break;
//            }
//            // only consider the first occurrence of a number
//            if (valid < i && i < num.size() && num[i] == num[i - 1]) {
//                continue;
//            }
//            // go recursive
//            path.push_back(num[i]);
//            recursiveSum(num, result, path, i + 1, remaining - num[i]);
//            path.pop_back();
//        }
//    }
//};

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(begin(num), end(num));
        vector<vector<int>> result;
        vector<int> path;
        recursiveComb(num, target, 0, 0, result, path);
        return result;
    }
    
private:
    void recursiveComb(vector<int> &num, int target, int sum, int k, vector<vector<int>> &result, vector<int> &path) {
        if (target == sum) {
            result.push_back(path);
            return;
        }
        
        // no answer
        if (k >= num.size() || num[k] > target - sum) return;
        
        // add cur
        path.push_back(num[k]);
        sum += num[k];
        recursiveComb(num, target, sum, k+1, result, path);
        path.pop_back();
        sum -= num[k];
        
        // jump to next diff number
        while (++k < num.size() && num[k-1] == num[k]);
        recursiveComb(num, target, sum, k, result, path);
        return;
    }
};
