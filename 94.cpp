/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Solution {
    void dfs(TreeNode* node, vector<int> &res){
        if (node != nullptr){
            this->dfs(node->left, res);
            res.push_back(node->val);
            this->dfs(node->right, res);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        this->dfs(root, res);
        return res;
    }
};
