
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *pre = new TreeNode(INT_MIN);
        TreeNode *wrong = new TreeNode(0);
        TreeNode *wrongNext = new TreeNode(0);
        dfs(root, pre, wrong, wrongNext);
        if (wrong->left) {
            if (wrong->right)
                swap(wrong->left->val, wrong->right->val);
            else
                swap(wrong->left->val, wrongNext->val);
        }
    }
    
    void dfs(TreeNode *node, TreeNode *&pre, TreeNode *wrong, TreeNode *&wrongNext) {
        if (!node || wrong->right) return;
        dfs(node->left, pre, wrong, wrongNext);
        if( !wrong->right && pre->val > node->val) {
            if (!wrong->left) wrong->left = pre, wrongNext = node;
            else wrong->right = node;
        }
        pre = node;
        dfs(node->right, pre, wrong, wrongNext);
    }
};