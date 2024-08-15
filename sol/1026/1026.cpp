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
    void ancestors(TreeNode *node, int ancestorMin, int ancestorMax, int &res){
        if (node == nullptr){
            return;
        }
        res = max(res, max(abs(node->val - ancestorMin), abs(node->val - ancestorMax)));
        ancestorMin = min(ancestorMin, node->val);
        ancestorMax = max(ancestorMax, node->val);
        this->ancestors(node->left, ancestorMin, ancestorMax, res);
        this->ancestors(node->right, ancestorMin, ancestorMax, res);
    }
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        this->ancestors(root, root->val, root->val, res);
        return res;
    }
};
