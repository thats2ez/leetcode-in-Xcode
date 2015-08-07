//
//  Count Complete Tree Nodes.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/25/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Count_Complete_Tree_Nodes_h
#define Count_Complete_Tree_Nodes_h


// * Definition for a binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = maxHeight(root);
        if (!h) return 0;
        int begin = 1 << (h - 1), end = (1 << h) - 1;
        // cout << begin << " " << end << endl;
        while (begin < end) {
            int mid = begin + (end - begin + 1) / 2;
            if (exist(root, mid)) {
                begin = mid;
            } else {
                end = mid - 1;
            }
        }
        return begin;
    }
    
private:
    int maxHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }
    
    bool exist(TreeNode* root, int n) {
        cout << n << endl;
        if (!root || !n) return false;
        stack<bool> s;
        while (n) {
            bool last = n & 1;
            s.push(last);
            n >>= 1;
        }
        s.pop();
        while (!s.empty()) {
            if (!root) return false;
            if (s.top()) {
                root = root->right;
            } else {
                root = root->left;
            }
            s.pop();
        }
        return root != nullptr;
    }
};

#endif /* Count_Complete_Tree_Nodes_h */
