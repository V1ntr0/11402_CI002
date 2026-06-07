class Solution {
public:
    int dfs(TreeNode* node, int cur) {
        if (!node) return 0;

        cur = cur * 2 + node->val;
        
        if (!node->left && !node->right) {
            return cur;
        }

        return dfs(node->left, cur) + dfs(node->right, cur);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};