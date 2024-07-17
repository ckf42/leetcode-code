#include <unordered_set>

struct Solution {
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        if (root == nullptr){
            return res;
        }
        if (to_delete.size() == 0){
            res.push_back(root);
            return res;
        }
        unordered_set<int> target(to_delete.begin(), to_delete.end());
        TreeNode foo(0, root, nullptr);
        vector<TreeNode*> st;
        vector<char> statSt;
        st.push_back(root);
        st.push_back(&foo);
        statSt.push_back(0);
        while (!st.empty()){
            TreeNode *parent = st.back();
            st.pop_back();
            TreeNode *node = st.back();
            st.pop_back();
            bool recorded = statSt.back() == 1;
            statSt.pop_back();
            if (node == nullptr){
                continue;
            }
            if (target.contains(node->val)){
                target.erase(node->val);
                if (parent->left == node){
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
                st.push_back(node->left);
                st.push_back(node);
                statSt.push_back(0);
                st.push_back(node->right);
                st.push_back(node);
                statSt.push_back(0);            
            } else {
                if (!recorded){
                    res.push_back(node);
                }
                st.push_back(node->left);
                st.push_back(node);
                statSt.push_back(1);
                st.push_back(node->right);
                st.push_back(node);
                statSt.push_back(1);  
            }
        }
        return res;
    }
};
