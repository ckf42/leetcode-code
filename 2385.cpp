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
    int getContri(TreeNode *node, bool &isInSubtree, int start, int &maxDist){
        if (node == nullptr){
            isInSubtree = false;
            return -1;
        }
        bool isInLeft, isInRight;
        int leftContri = this->getContri(node->left, isInLeft, start, maxDist);
        int rightContri = this->getContri(node->right, isInRight, start, maxDist);
        if (node->val == start){
            maxDist = max(maxDist, max(leftContri, rightContri) + 1);
            isInSubtree = true;
            return 0;
        } else if (isInLeft || isInRight){
            maxDist = max(maxDist, leftContri + rightContri + 2);
            isInSubtree = true;
            return (isInLeft ? leftContri : rightContri) + 1;
        } else {
            isInSubtree = false;
            return max(leftContri, rightContri) + 1;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        int maxDist = 0;
        bool isInSubtree;
        this->getContri(root, isInSubtree, start, maxDist);
        return maxDist;
    }
};
