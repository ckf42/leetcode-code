struct Solution {
    int dfs(TreeNode *node, int &res){
        if (node == nullptr){
            return 0;
        }
        int lf = this->dfs(node->left, res);
        int rf = this->dfs(node->right, res);
        res = max(res, node->val + max(lf, 0) + max(rf, 0));
        return node->val + max(0, max(lf, rf));
    }
    inline int maxPathSum(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int res = root->val;
        this->dfs(root, res);
        return res;
    }
};
