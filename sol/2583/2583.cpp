#include <deque>

struct Solution {
    using ll = long long;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> h;
        deque<TreeNode *> lvl;
        lvl.push_back(root);
        while (!lvl.empty()){
            int n = lvl.size();
            ll accum = 0;
            while (n-- > 0){
                TreeNode *ptr = lvl.front();
                lvl.pop_front();
                accum += ptr->val;
                if (ptr->left != nullptr){
                    lvl.push_back(ptr->left);
                }
                if (ptr->right != nullptr){
                    lvl.push_back(ptr->right);
                }
            }
            h.push(accum);
            if (h.size() > k){
                h.pop();
            }
        }
        if (h.size() < k){
            return -1;
        } else {
            return h.top();
        }

    }
};
