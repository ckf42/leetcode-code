#include <queue>

struct Solution {
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int s = q.size();
            vector<int> lvl;
            while (s-- > 0){
                TreeNode *node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if (node->left != nullptr){
                    q.push(node->left);
                }
                if (node->right != nullptr){
                    q.push(node->right);
                }
            }
            res.push_back(lvl);
        }
        ranges::reverse(res);
        return res;
    }
};
