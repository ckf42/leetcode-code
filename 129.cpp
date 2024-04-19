struct Solution {
    int dfs(TreeNode *node, int prefix){
        if (node == nullptr){
            return 0;
        }
        prefix *= 10;
        prefix += node->val;
        if (node->left == nullptr && node->right == nullptr){
            return prefix;
        }
        return dfs(node->left, prefix) + dfs(node->right, prefix);
    }
    inline int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
