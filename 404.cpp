struct Solution {
    int traversal(TreeNode *node, bool isLeft){
        if (node == nullptr){
            return 0;
        }
        if (isLeft && node->left == nullptr && node->right == nullptr){
            return node->val;
        }
        return traversal(node->left, true) + traversal(node->right, false);
    }
    inline int sumOfLeftLeaves(TreeNode* root) {
        return traversal(root, false);
    }
};
