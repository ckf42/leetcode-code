#include <deque>

struct Solution {
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        bool fromFront = true;
        while (!q.empty()){
            vector<int> lvl;
            int s = q.size();
            while (s-- > 0){
                if (fromFront){
                    TreeNode *node = q.front();
                    q.pop_front();
                    lvl.push_back(node->val);
                    if (node->left != nullptr){
                        q.push_back(node->left);
                    }
                    if (node->right != nullptr){
                        q.push_back(node->right);
                    }
                } else {
                    TreeNode *node = q.back();
                    q.pop_back();
                    lvl.push_back(node->val);
                    if (node->right != nullptr){
                        q.push_front(node->right);
                    }
                    if (node->left != nullptr){
                        q.push_front(node->left);
                    }
                }
            }
            res.push_back(lvl);
            fromFront = !fromFront;
        }
        return res;
    }
};
