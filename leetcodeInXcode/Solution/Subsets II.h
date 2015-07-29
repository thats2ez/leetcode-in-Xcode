//
//  Subsets II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/6/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
//    vector<vector<int>> subsetsWithDup(vector<int> &S) {
//        vector<vector<int>> result;
//        sort(S.begin(), S.end());
//        for (int i = 0; i < pow(2, S.size()); i++) {
//            permutate(result, S, i);
//        }
//        return result;
//    }
//    
//    void permutate(vector<vector<int>> &result, vector<int> &S, int pattern) {
//        for (int i = 0, bit = 1; i < S.size() - 1; i++, bit <<= 1) {
//            if ((S[i] == S[i+1]) && !(pattern & bit) && (pattern & (bit << 1))) {
//                return;
//            }
//        }
//        vector<int> subset;
//        for (int i = 0; i < S.size(); i++, pattern >>= 1) {
//            if (pattern & 1) {
//                subset.push_back(S[i]);
//            }
//        }
//        result.push_back(subset);
//    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, int> occur;
        for (int i : nums) {
            occur[i]++;
        }
        vector<int> path;
        auto it = occur.begin();
        recursivePrint(occur, it, result, path);
        return result;
    }
    
    void recursivePrint(map<int, int> &occur, map<int, int>::iterator &it, vector<vector<int>> &result, vector<int> &path) {
        // end state
        if (it == occur.end()) {
            result.push_back(path);
            return;
        }
        // goes deep
        int count = it->second;
        int index = it->first;
        it++;
        recursivePrint(occur, it, result, path);
        for (int i = 0; i < count; i++) {
            path.push_back(index);
            recursivePrint(occur, it, result, path);
        }
        // goes back
        it--;
        for (int i = 0; i < count; i++) {
            path.pop_back();
        }
        
        return;
    }

};