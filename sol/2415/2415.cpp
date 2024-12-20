struct Solution {
    void dfs(TreeNode *l, TreeNode *r, bool flip){
        if (l == nullptr){
            return;
        }
        if (flip){
            swap(l->val, r->val);
        }
        this->dfs(l->left, r->right, !flip);
        this->dfs(r->left, l->right, !flip);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        this->dfs(root->left, root->right, true);
        return root;
    }
};
