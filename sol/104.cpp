struct Solution {
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        return max(this->maxDepth(root->left), this->maxDepth(root->right)) + 1;
    }
};
