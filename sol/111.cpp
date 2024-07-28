#include <queue>

struct Solution {
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int dep = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int s = q.size();
            for (int i = 0; i < s; ++i){
                TreeNode *node = q.front();
                q.pop();
                if (node->left == nullptr && node->right == nullptr){
                    return dep;
                }
                if (node->left != nullptr){
                    q.push(node->left);
                }
                if (node->right != nullptr){
                    q.push(node->right);
                }
            }
            ++dep;
        }
        return 0;
    }
};
