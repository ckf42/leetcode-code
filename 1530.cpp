#include <map>

struct Solution {
    using Dict = map<int, int>;

    Dict dfs(TreeNode *node, int distance, int &count){
        Dict d;
        if (node == nullptr){
            return d;
        }
        if (node->left == nullptr && node->right == nullptr){
            d[0] = 1;
            return d;
        }
        Dict ld = dfs(node->left, distance, count);
        Dict rd = dfs(node->right, distance, count);
        for (auto &lpr : ld){
            for (auto &rpr : rd){
                if (lpr.first + rpr.first + 2 > distance){
                    break;
                }
                count += lpr.second * rpr.second;
            }
        }
        for (auto &pr : ld){
            if (pr.first >= distance - 2){
                break;
            }
            d[pr.first + 1] += pr.second;
        }
        for (auto &pr : rd){
            if (pr.first >= distance - 2){
                break;
            }
            d[pr.first + 1] += pr.second;
        }
        return d;
    }

    inline int countPairs(TreeNode* root, int distance) {
        int count = 0;
        this->dfs(root, distance, count);
        return count;
    }
};
