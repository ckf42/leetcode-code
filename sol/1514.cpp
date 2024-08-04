#include <unordered_map>

struct Solution {
    using pr = pair<double, int>;
    double maxProbability(
            int n, vector<vector<int>>& edges, vector<double>& succProb,
            int start_node, int end_node) {
        unordered_map<int, vector<pr>> edgeList;
        for (int i = 0; i < edges.size(); ++i){
            if (succProb[i] == 0.0){
                continue;
            }
            double p = -log(succProb[i]);
            edgeList[edges[i][0]].push_back({p, edges[i][1]});
            edgeList[edges[i][1]].push_back({p, edges[i][0]});
        }
        vector<double> dist(n, -1);
        vector<pr> h;
        h.push_back({0, start_node});
        while (!h.empty()){
            ranges::pop_heap(h);
            double d = -h.back().first;
            int node = h.back().second;
            h.pop_back();
            if (dist[node] != -1){
                continue;
            }
            dist[node] = d;
            if (node == end_node){
                return exp(-d);
            }
            for (auto [w, v] : edgeList[node]){
                if (dist[v] == -1){
                    h.push_back({-d - w, v});
                    ranges::push_heap(h);
                }
            }
        }
        return 0;
    }
};
