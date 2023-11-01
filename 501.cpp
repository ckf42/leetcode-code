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
    void inorder(TreeNode *node, int &lastVal, int &count, int &maxCount, vector<int> &res){
        if (node == nullptr){
            return;
        }
        inorder(node->left, lastVal, count, maxCount, res);
        if (node->val != lastVal){
            count = 1;
            lastVal = node->val;
        } else {
            ++count;
        }
        if (count > maxCount){
            maxCount = count;
            res.clear();
        }
        if (count == maxCount){
            res.push_back(lastVal);
        }
        inorder(node->right, lastVal, count, maxCount, res);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int lastVal = -100001, count = 0, maxCount = 0;
        inorder(root, lastVal, count, maxCount, res);
        return res;
    }
};
