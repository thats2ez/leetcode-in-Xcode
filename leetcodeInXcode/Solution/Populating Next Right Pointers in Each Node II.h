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
        node->next = right;
        if (!node->left && !node->right)
            return;
        TreeLinkNode *nextLevelRight = leftMostChild(right);
        if (node->right) {
            dfs(node->right, nextLevelRight);
            nextLevelRight = node->right;
        }
        if (node->left) {
            dfs(node->left, nextLevelRight);
        }
    }
    
    TreeLinkNode *leftMostChild(TreeLinkNode *node) {
        if (!node)
            return NULL;
        else if (node->left)
            return node->left;
        else if (node->right)
            return node->right;
        else
            return leftMostChild(node->next);
    }
};