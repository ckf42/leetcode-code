/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <unordered_map>
#include <unordered_set>

struct Solution {
    void buildParent(
            TreeNode *node,
            TreeNode *parent,
            unordered_map<TreeNode*, TreeNode*> &parentMap,
            TreeNode *&target,
            int start){
        if (node->val == start){
            target = node;
        }
        parentMap[node] = parent;
        if (node->left != nullptr){
            buildParent(node->left, node, parentMap, target, start);
        }
        if (node->right != nullptr){
            buildParent(node->right, node, parentMap, target, start);
        }
    }

    int dfs(
            TreeNode *node, 
            unordered_map<TreeNode*, TreeNode*> &parent,
            unordered_set<TreeNode*> &visited,
            int depth){
        TreeNode * arr[3] = {node->left, node->right, parent[node]};
        int res = depth;
        visited.insert(node);
        for (int i = 0; i < 3; ++i){
            if (arr[i] != nullptr && !visited.contains(arr[i])){
                res = max(res, dfs(arr[i], parent, visited, depth) + 1);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode *target = nullptr;
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, nullptr, parent, target, start);
        unordered_set<TreeNode*> visited;
        return dfs(target, parent, visited, 0);
    }
};
