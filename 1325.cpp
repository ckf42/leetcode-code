struct Solution {
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr){
            return root;
        }
        root->left = this->removeLeafNodes(root->left, target);
        root->right = this->removeLeafNodes(root->right, target);
        if (root->val == target && root->left == nullptr && root->right == nullptr){
            return nullptr;
        } else {
            return root;
        }
    }
};
