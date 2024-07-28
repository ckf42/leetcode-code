struct Solution {
    bool isMirror(TreeNode* l, TreeNode* r){
        if (l == nullptr || r == nullptr){
            return l == nullptr && r == nullptr;
        }
        return l->val == r->val 
                && this->isMirror(l->left, r->right)
                && this->isMirror(l->right, r->left);
    }
    inline bool isSymmetric(TreeNode* root) {
        return this->isMirror(root, root);
    }
};
