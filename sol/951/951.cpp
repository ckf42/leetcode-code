struct Solution {
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr){
            return root1 == nullptr && root2 == nullptr;
        }
        if (root1->val != root2->val){
            return false;
        }
        TreeNode *l1 = root1->left, *r1 = root1->right, *l2 = root2->left, *r2 = root2->right;
        if (r1 == nullptr || (l1 != nullptr && l1->val > r1->val)){
            swap(l1, r1);
        }
        if (r2 == nullptr || (l2 != nullptr && l2->val > r2->val)){
            swap(l2, r2);
        }
        return this->flipEquiv(l1, l2) && this->flipEquiv(r1, r2);
    }
};
