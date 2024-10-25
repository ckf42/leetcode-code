#include <queue>
#include <unordered_map>

struct Solution {
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        deque<pair<TreeNode *, TreeNode *>> lvl;
        if (root->left != nullptr){
            lvl.emplace_back(root->left, root);
        }
        if (root->right != nullptr){
            lvl.emplace_back(root->right, root);
        }
        while (!lvl.empty()){
            int n = lvl.size(), total = 0;
            unordered_map<TreeNode *, int> d;
            vector<pair<TreeNode *, TreeNode *>> st;
            while (n-- > 0){
                auto [node, par] = lvl.front();
                lvl.pop_front();
                d[par] += node->val;
                total += node->val;
                st.emplace_back(node, par);
                if (node->left != nullptr){
                    lvl.emplace_back(node->left, node);
                }
                if (node->right != nullptr){
                    lvl.emplace_back(node->right, node);
                }
            }
            for (auto [node, par] : st){
                node->val = total - d[par];
            }
        }
        return root;
    }
};
