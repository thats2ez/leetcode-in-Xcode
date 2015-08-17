//
//  Binary Tree Paths.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 8/16/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Binary_Tree_Paths_h
#define Binary_Tree_Paths_h

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        dfs(root, result, path);
        return result;
    }
    
private:
    void dfs(TreeNode* node, vector<string> &result, string &path) {
        // end
        if (!node) return;
        
        int length = path.length();
        path += "->";
        path += to_string(node->val);
        
        if (!node->left && !node->right) {
            result.push_back(path.substr(2, path.length() - 2));
        } else {
            if (node->left) dfs(node->left, result, path);
            if (node->right) dfs(node->right, result, path);
        }
        
        path.resize(length);
        return;
    }
};

#endif /* Binary_Tree_Paths_h */
