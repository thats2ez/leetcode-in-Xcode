//
//  Binary Tree Level Order Traversal II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/11/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        q.push(root);
        // counter for levels
        int cur = 1, next = 0;
        vector<int> level;
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node) {
                level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
                next += 2;
            }
            // a level is completed
            if (--cur == 0) {
                swap(cur, next);
                // insert to the front
                if (!level.empty()) {
                    result.insert(result.begin(), level);
                    level.clear();
                }
            }
        }
        return result;
    }
};