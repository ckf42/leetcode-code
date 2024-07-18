struct Solution {
    bool verify(TreeNode *node, long lb, long ub){
        if (node == nullptr){
            return true;
        }
        if (node->val <= lb || node->val >= ub) {
            return false;
        }
        return this->verify(node->left, lb, node->val) && this->verify(node->right, node->val, ub);
    }
    inline bool isValidBST(TreeNode* root) {
        return this->verify(root, -2147483649l, 2147483648l);
    }
};
