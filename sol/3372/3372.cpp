#include <unordered_map>

struct Solution {
    int dfs(int node, int forbid, int limit, const unordered_map<int, vector<int>> &adj){
        if (limit == 0){
            return 1;
        }
        int count = 1;
        for (int nb : adj.at(node)){
            if (nb == forbid){
                continue;
            }
            count += this->dfs(nb, node, limit - 1, adj);
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        if (k == 0){
            return vector<int>(n, 1);
        }
        unordered_map<int, vector<int>> adj1, adj2;
        for (auto &e : edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        int secondMost = 0;
        for (int i = 0; i < m; ++i){
            secondMost = max(secondMost, this->dfs(i, -1, k - 1, adj2));
        }
        vector<int> res(n, secondMost);
        for (int i = 0; i < n; ++i){
            res[i] += this->dfs(i, -1, k, adj1);
        }
        return res;
    }
};
