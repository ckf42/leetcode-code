struct Solution {
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val){
            root = root->val < val ? root->right : root->left;
        }
        return root;
    }
};
