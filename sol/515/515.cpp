#include <queue>

struct Solution {
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr){
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size(), maxVal = q.front()->val;
            while (n-- > 0){
                TreeNode *node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left != nullptr){
                    q.push(node->left);
                }
                if (node->right != nullptr){
                    q.push(node->right);
                }
            }
            res.push_back(maxVal);
        }

        return res;
    }
};
