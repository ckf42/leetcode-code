struct Solution {
    int dfs(TreeNode *node, int &total){
        if (node == nullptr){
            return 0;
        }
        int res = node->val - 1, subres = dfs(node->left, total);
        total += abs(subres);
        res += subres;
        subres = dfs(node->right, total);
        total += abs(subres);
        res += subres;
        return res;
    }

    inline int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
