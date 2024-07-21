struct Solution {
    inline static string join(vector<string> &prefix){
        string res = prefix[0];
        for (int i = 1; i < prefix.size(); ++i){
            res += "->" + prefix[i];
        }
        return res;
    }
    void dfs(TreeNode *node, vector<string> &prefix, vector<string> &res){
        if (node == nullptr){
            return;
        }
        prefix.push_back(to_string(node->val));
        if (node->left == nullptr && node->right == nullptr){
            res.push_back(this->join(prefix));
        } else {
            this->dfs(node->left, prefix, res);
            this->dfs(node->right, prefix, res);
        }
        prefix.pop_back();
    }
    inline vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res, prefix;
        vector<TreeNode*> st;
        if (root == nullptr){
            return res;
        }
        this->dfs(root, prefix, res);
        return res;
    }
};
