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
    void dfs(TreeNode *node, const int &low, const int &high, int &res){
        if (node == nullptr){
            return;
        }
        if (low <= node->val && node->val <= high){
            res += node->val;
        }
        if (low < node->val){
            dfs(node->left, low, high, res);
        }
        if (node->val < high){
            dfs(node->right, low, high, res);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        dfs(root, low, high, res);
        return res;
    }
};
