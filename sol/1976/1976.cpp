#include <unordered_map>

struct Solution {
    static constexpr int m = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> edgeList;
        for (auto &e : roads){
            edgeList[e[0]].push_back({e[1], e[2]});
            edgeList[e[1]].push_back({e[0], e[2]});
        }
        vector<long> dist(n, -1);
        vector<int> memo(n, 0);
        dist[0] = 0;
        memo[0] = 1;
        vector<pair<long, int>> h;
        h.push_back({0, 0});
        while (!h.empty()){
            ranges::pop_heap(h);
            auto [d, node] = h.back();
            h.pop_back();
            for (auto [v, t] : edgeList[node]){
                long w = -d + t;
                if (dist[v] == -1 || dist[v] > w){
                    dist[v] = w;
                    memo[v] = memo[node];
                    h.push_back({-w, v});
                    ranges::push_heap(h);
                } else if (dist[v] == w){
                    memo[v] = (memo[v] + memo[node]) % this->m;
                }
            }
        }
        return memo[n - 1];
    }
};
