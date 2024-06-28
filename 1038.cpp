struct Solution {
    void rot(TreeNode *node, int &cumsum){
        if (node->right != nullptr){
            this->rot(node->right, cumsum);
        }
        node->val += cumsum;
        cumsum = node->val;
        if (node->left != nullptr){
            this->rot(node->left, cumsum);
        }
    }
    inline TreeNode* bstToGst(TreeNode* root) {
        int cumsum = 0;
        this->rot(root, cumsum);
        return root;
    }
};
