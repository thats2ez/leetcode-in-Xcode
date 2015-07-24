//
//  Search a 2D Matrix II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/23/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Search_a_2D_Matrix_II_h
#define Search_a_2D_Matrix_II_h

class Solution {
public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        for (int i = 0; i < matrix.size(); i++) {
//            if (binarySearch(matrix[i], target)) return true;
//        }
//        return false;
//    }
//    
//    bool binarySearch(vector<int> &row, int target) {
//        int i = 0, j = (int)row.size() - 1;
//        while (i <= j) {
//            int mid = i + (j - i) / 2;
//            if (row[mid] == target) {
//                return true;
//            } else if (row[mid] > target) {
//                j = mid - 1;
//            } else {
//                i = mid + 1;
//            }
//        }
//        return false;
//    }
//};

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    for (int i = 0, j = (int)matrix[0].size() - 1; i < (int)matrix.size() && j >= 0;) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}

#endif /* Search_a_2D_Matrix_II_h */
