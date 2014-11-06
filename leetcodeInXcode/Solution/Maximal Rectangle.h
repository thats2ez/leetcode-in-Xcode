//
//  Maximal Rectangle.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/5/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if ( matrix.size() < 1 ||  matrix[0].size() < 1)
            return 0;
        int result = 0;
        vector<vector<int> > height = vector<vector<int> >(matrix.size() + 1, vector<int>(matrix[0].size(), 0));
        for (int i=1; i < matrix.size() + 1; i++) {
            for (int j=0; j < matrix[0].size(); j++) {
                height[i][j] = matrix[i-1][j] == '1' ? height[i-1][j] + 1 : 0;
            }
            result = max(result, largestRectangleArea(height[i]));
        }
        return result;
    }
    
private:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int result = 0;
        height.push_back(0);
        for (int i=0; i < height.size(); ) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                int top = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                int area = height[top] * width;
                result = max(result, area);
            }
        }
        return result;
    }
};