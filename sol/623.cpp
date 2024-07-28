struct Solution {
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr){
            return root;
        }
        if (depth == 1){
            return new TreeNode(val, root, nullptr);
        }
        if (depth == 2){
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
            return root;
        }
        root->left = this->addOneRow(root->left, val, depth - 1);
        root->right = this->addOneRow(root->right, val, depth - 1);
        return root;
    }
};
