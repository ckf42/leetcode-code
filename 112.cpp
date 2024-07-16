struct Solution {
    bool dfs(TreeNode *node, int res){
        if (node == nullptr){
            return false;
        }
        res -= node->val;
        if (node->left == nullptr && node->right == nullptr){
            return res == 0;
        }
        return this->dfs(node->left, res) || this->dfs(node->right, res);
    }
    inline bool hasPathSum(TreeNode* root, int targetSum) {
        return this->dfs(root, targetSum);
    }
};
