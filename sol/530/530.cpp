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
    int getSub(TreeNode *root, int &minVal, int &maxVal){
        assert(root != nullptr);
        int diff = 100001, subMin, subMax;
        minVal = root->val;
        maxVal = root->val;
        if (root->left){
            diff = min(diff, this->getSub(root->left, minVal, subMax));
            diff = min(diff, root->val - subMax);
        }
        if (root->right){
            diff = min(diff, this->getSub(root->right, subMin, maxVal));
            diff = min(diff, subMin - root->val);
        }
        return diff;
    }

    int getMinimumDifference(TreeNode* root) {
        int minVal, maxVal;
        return this->getSub(root, minVal, maxVal);
    }
};
