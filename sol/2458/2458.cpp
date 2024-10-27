#include <unordered_map>

struct Solution {
    using umii = unordered_map<int, int>;
    void dfs(
            TreeNode *node, int dep,
            vector<int> &traversalOrder, umii &depths, umii &enterIdx, umii &exitIdx){
        enterIdx[node->val] = traversalOrder.size();
        traversalOrder.push_back(node->val);
        depths[node->val] = dep;
        if (node->left != nullptr){
            this->dfs(node->left, dep + 1, traversalOrder, depths, enterIdx, exitIdx);
        }
        if (node->right != nullptr){
            this->dfs(node->right, dep + 1, traversalOrder, depths, enterIdx, exitIdx);
        }
        exitIdx[node->val] = traversalOrder.size();
        traversalOrder.push_back(node->val);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> traversalOrder;
        umii depths, enterIdx, exitIdx;
        this->dfs(root, 0, traversalOrder, depths, enterIdx, exitIdx);
        int nn = traversalOrder.size(), m = queries.size();
        vector<int> maxFromLeft(nn), maxFromRight(nn), res(m);
        maxFromLeft[0] = 0;
        maxFromRight[nn - 1] = 0;
        for (int i = 1; i < nn; ++i){
            maxFromLeft[i] = max(maxFromLeft[i - 1], depths[traversalOrder[i]]);
            maxFromRight[nn - 1 - i] = max(maxFromRight[nn - i], depths[traversalOrder[nn - 1 - i]]);
        }
        for (int i = 0; i < m; ++i){
            res[i] = max(
                maxFromLeft[enterIdx[queries[i]] - 1],
                maxFromRight[exitIdx[queries[i]] + 1]
            );
        }
        return res;
    }
};
