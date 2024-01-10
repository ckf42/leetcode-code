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
#include <algorithm>

struct Solution {
    void leafSeq(TreeNode* root, vector<int> &res){
        if (root == nullptr){
            return;
        }
        if (root->left == nullptr && root->right == nullptr){
            res.push_back(root->val);
            return;
        }
        this->leafSeq(root->left, res);
        this->leafSeq(root->right, res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        this->leafSeq(root1, res1);
        this->leafSeq(root2, res2);
        return equal(res1.begin(), res1.end(), res2.begin(), res2.end());
    }
};
