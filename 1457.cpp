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
    int dfs(TreeNode *node, int mask){
        if (node == nullptr){
            return 0;
        }
        mask ^= (1 << node->val);
        if (node->left == nullptr && node->right == nullptr){
            return __builtin_popcount(mask) <= 1 ? 1 : 0;
        }
        return this->dfs(node->left, mask) + this->dfs(node->right, mask);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
};
