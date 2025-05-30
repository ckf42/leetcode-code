#include <unordered_map>

struct Solution {
    using Adj = unordered_map<int, vector<int>>;
    void dfs(int node, int gpidx, Adj &adj, vector<int> &gp){
        if (gp[node] != 0){
            return;
        }
        gp[node] = gpidx;
        for (int nb : adj[node]){
            this->dfs(nb, 3 - gpidx, adj, gp);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        Adj adj1, adj2;
        for (auto &e : edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        vector<int> gp1(n, 0), gp2(m, 0);
        this->dfs(0, 1, adj1, gp1);
        this->dfs(0, 1, adj2, gp2);
        int count1 = 0, count2 = 0;
        for (int x : gp1){
            count1 += (x == 1);
        }
        for (int x : gp2){
            count2 += (x == 1);
        }
        count2 = max(count2, m - count2);
        for (int i = 0; i < n; ++i){
            if (gp1[i] == 1){
                gp1[i] = count1 + count2;
            } else {
                gp1[i] = n - count1 + count2;
            }
        }
        return gp1;
    }
};
