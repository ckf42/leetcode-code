struct Solution {
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr){
            return res;
        }
        vector<TreeNode*> st;
        st.push_back(root);
        while (!st.empty()){
            TreeNode *node = st.back();
            st.pop_back();
            res.push_back(node->val);
            if (node->right != nullptr){
                st.push_back(node->right);
            }
            if (node->left != nullptr){
                st.push_back(node->left);
            }
        }
        return res;
    }
};
