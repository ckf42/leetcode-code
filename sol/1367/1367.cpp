struct Solution {
    bool checker(TreeNode *node, ListNode *ptr){
        if (ptr == nullptr){
            return true;
        }
        if (node == nullptr || node->val != ptr->val){
            return false;
        }
        return this->checker(node->left, ptr->next) || this->checker(node->right, ptr->next);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode *> st = {root};
        while (!st.empty()){
            TreeNode *node = st.back();
            st.pop_back();
            if (this->checker(node, head)){
                return true;
            }
            if (node->left != nullptr){
                st.push_back(node->left);
            }
            if (node->right != nullptr){
                st.push_back(node->right);
            }
        }
        return false;
    }
};
