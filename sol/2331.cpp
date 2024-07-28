struct Solution {
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr){
            return root->val == 1;
        } else if (root->val == 2){
            return this->evaluateTree(root->left) || this->evaluateTree(root->right);
        } else {
            return this->evaluateTree(root->left) && this->evaluateTree(root->right);
        }
    }
};
