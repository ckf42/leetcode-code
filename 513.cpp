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
    void nrl(TreeNode *node, int h, int &res, int &height){
        if (node == nullptr){
            return;
        }
        if (h >= height){
            height = h;
            res = node->val;
        }
        ++h;
        this->nrl(node->right, h, res, height);
        this->nrl(node->left, h, res, height);
    }
    int findBottomLeftValue(TreeNode* root) {
        int res = root->val, height = 0;
        this->nrl(root, 0, res, height);
        return res;
    }
};
