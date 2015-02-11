//
//  Generate Parentheses.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/10/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        recursiveGenerate(result, "", 0, 0, n);
        return result;
    }
    
    void recursiveGenerate(vector<string> &result, string path, int begin, int end, int n) {
        if (begin < n) {
            recursiveGenerate(result, path + "(", begin + 1, end, n);
        }
        
        if (begin > end) {
            recursiveGenerate(result, path + ")", begin, end + 1, n);
        }
        
        if (end == n) {
            result.push_back(path);
        }
    }
};