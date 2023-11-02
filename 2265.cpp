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
    void dfs(TreeNode *node, int &res, int &subSum, int &subCount){
        if (node == nullptr){
            subSum = subCount = 0;
            return;
        }
        subSum = node->val;
        subCount = 1;
        int childCount, childSum;
        dfs(node->left, res, childSum, childCount);
        subSum += childSum;
        subCount += childCount;
        dfs(node->right, res, childSum, childCount);
        subSum += childSum;
        subCount += childCount;
        if (subSum / subCount == node->val){
            ++res;
        }
    }

    int averageOfSubtree(TreeNode* root) {
        int res = 0, subSum, subCount;
        dfs(root, res, subSum, subCount);
        return res;
    }
};
