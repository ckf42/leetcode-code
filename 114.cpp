struct Solution {
    using pr = pair<TreeNode*, TreeNode*>;

    pr flatter(TreeNode *node){
        if (node == nullptr){
            return {nullptr, nullptr};
        }
        pr p = this->flatter(node->left), q = this->flatter(node->right);
        TreeNode *lh = p.first, *lt = p.second, *rh = q.first, *rt = q.second, *ptr = node;
        node->left = nullptr;
        if (lh != nullptr){
            ptr->right = lh;
            ptr = lt;
        }
        if (rh != nullptr){
            ptr->right = rh;
            ptr = rt;
        }
        return {node, ptr};
    }
    inline void flatten(TreeNode* root) {
        this->flatter(root);
    }
};
