struct Solution {
    int dfs(TreeNode *node, bool &isbal){
        if (node == nullptr){
            return 0;
        }
        int ld = this->dfs(node->left, isbal), rd = this->dfs(node->right, isbal);
        if (!isbal){
            return 0;
        }
        if (abs(ld - rd) > 1){
            isbal = false;
            return 0;
        }
        return max(ld, rd) + 1;
    }
    inline bool isBalanced(TreeNode* root) {
        bool isbal = true;
        this->dfs(root, isbal);
        return isbal;
    }
};
