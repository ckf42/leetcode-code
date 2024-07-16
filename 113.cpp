struct Solution {
    void dfs(TreeNode *node, int curr, vector<int> &rec, vector<vector<int>> &res){
        curr -= node->val;
        rec.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && curr == 0){
            res.push_back(rec);
        }
        if (node->left != nullptr){
            this->dfs(node->left, curr, rec, res);
        }
        if (node->right != nullptr){
            this->dfs(node->right, curr, rec, res);
        }
        rec.pop_back();
    }
    inline vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> rec;
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        this->dfs(root, targetSum, rec, res);
        return res;
    }
};
