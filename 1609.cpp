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
#include <queue>

struct Solution {
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> nodes;
        TreeNode *node;
        nodes.push(root);
        int remainder = 1, prevVal = 0, size = 1;
        while (size != 0){
            prevVal = 0;
            for (int i = 0; i < size; ++i){
                node = nodes.front();
                nodes.pop();
                if ((node->val & 1) != remainder){
                    return false;
                }
                if (prevVal != 0){
                    if (remainder == 1 ? prevVal >= node->val : prevVal <= node->val){
                        return false;
                    }
                }
                prevVal = node->val;
                if (node->left != nullptr){
                    nodes.push(node->left);
                }
                if (node->right != nullptr){
                    nodes.push(node->right);
                }
            }
            size = nodes.size();
            remainder ^= 1;
        }
        return true;
    }
};
