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
    TreeNode* postorder(TreeNode *node, int &dep){
        if (node == nullptr){
            dep = -1;
            return nullptr;
        }
        int leftDep, rightDep;
        TreeNode *leftRes = this->postorder(node->left, leftDep), 
                 *rightRes = this->postorder(node->right, rightDep);
        if (leftDep == rightDep){
            dep = leftDep + 1;
            return node;
        } else if (leftDep > rightDep){
            dep = leftDep + 1;
            return leftRes;
        } else {
            dep = rightDep + 1;
            return rightRes;
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int dep;
        return this->postorder(root, dep);
    }
};

