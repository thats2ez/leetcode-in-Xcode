//
//  main.cpp
//  leetcodeInXcode
//
//  Created by Kaiqi on 14/10/27.
//  Copyright (c) 2014年 edu.self. All rights reserved.
//

#include "Path Sum.h"

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    auto result = s.hasPathSum(root, 1);
    cout << result << endl;
    return 0;
}