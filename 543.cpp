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
    int dfs(TreeNode *node, int &res){
        if (node == nullptr){
            return 0;
        }
        int ld = this->dfs(node->left, res);
        int rd = this->dfs(node->right, res);
        res = max(res, ld + rd);
        return max(ld, rd) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        this->dfs(root, dia);
        return dia;
    }
};
