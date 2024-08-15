#include <queue>

struct Solution {
    int maxLevelSum(TreeNode* root) {
        int optSum = root->val, res = 1, lvl = 2;
        queue<TreeNode *> q;
        if (root->left != nullptr){
            q.push(root->left);
        }
        if (root->right != nullptr){
            q.push(root->right);
        }
        while (!q.empty()){
            int s = q.size(), tot = 0;
            while (s-- > 0){
                TreeNode *node = q.front();
                q.pop();
                tot += node->val;
                if (node->left != nullptr){
                    q.push(node->left);
                }
                if (node->right != nullptr){
                    q.push(node->right);
                }
            }
            if (tot > optSum){
                optSum = tot;
                res = lvl;
            }
            ++lvl;
        }
        return res;
    }
};
