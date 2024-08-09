struct Solution {
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ptr = root;
        while (ptr != nullptr){
            if (ptr->val == p->val || ptr->val == q->val){
                return ptr;
            }
            if (ptr->val > p->val && ptr->val > q->val){
                ptr = ptr->left;
            } else if (ptr->val < p->val && ptr->val < q->val){
                ptr = ptr->right;
            } else {
                return ptr;
            }
        }
        return nullptr;
    }
};
