// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        dfs(root, NULL);
    }
    
    void dfs(TreeLinkNode *node, TreeLinkNode *right) {
        if (!node)
            return;
        node -> next = right;
        dfs(node->left, node->right);
        dfs(node->right, right ? right->left : NULL);
    }
};