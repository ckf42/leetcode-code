struct Solution {
    TreeNode* recoverFromPreorder(string &traversal) {
        TreeNode *foobar = new TreeNode(0);
        vector<TreeNode *> st{foobar};
        int valBuff = 0;
        auto it = traversal.begin();
        while (it != traversal.end()){
            int dep = 1;
            while (it != traversal.end() && *it == '-'){
                ++dep;
                ++it;
            }
            valBuff = 0;
            while (it != traversal.end() && *it != '-'){
                valBuff *= 10;
                valBuff += *it - '0';
                ++it;
            }
            while (dep != st.size()){
                st.pop_back();
            }
            TreeNode *newNode = new TreeNode(valBuff);
            if (st.back()->left == nullptr){
                st.back()->left = newNode;
            } else {
                st.back()->right = newNode;
            }
            st.push_back(newNode);
        }
        return foobar->left;
    }
};
