struct Solution {
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> expanded(n, false);
        int res = 0;
        vector<pair<int, int>> buff;
        buff.push_back({0, 0});
        while (!buff.empty()){
            auto [node, prev] = buff.back();
            if (!expanded[node]){
                expanded[node] = true;
                for (auto nb : adj[node]){
                    if (!expanded[nb]){
                        buff.push_back({nb, node});
                    }
                }
            } else {
                values[node] %= k;
                if (values[node] == 0){
                    ++res;
                } else if (node != 0){
                    values[prev] = (values[prev] + values[node]) % k;
                }
                buff.pop_back();
            }
        }
        return res;
    }
};
