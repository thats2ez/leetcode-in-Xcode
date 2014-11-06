
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
            result.push_back(node->val);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};