#include <deque>

struct Solution {
    int minimumOperations(TreeNode* root) {
        int count = 0;
        deque<TreeNode *> q;
        q.push_back(root);
        while (!q.empty()){
            int n = q.size();
            vector<int> nextIdx(n);
            ranges::iota(nextIdx, 0);
            ranges::sort(nextIdx, [&](int i, int j){return q[i]->val < q[j]->val;});
            vector<bool> visited(n, false);
            for (int i = 0; i < n; ++i){
                if (visited[i]){
                    continue;
                }
                int ptr = i, loopLen = -1;
                while (!visited[ptr]){
                    visited[ptr] = true;
                    ptr = nextIdx[ptr];
                    ++loopLen;
                }
                count += loopLen;
            }
            while (n-- > 0){
                TreeNode *node = q.front();
                q.pop_front();
                if (node->left != nullptr){
                    q.push_back(node->left);
                }
                if (node->right != nullptr){
                    q.push_back(node->right);
                }
            }
        }
        return count;
    }
};
