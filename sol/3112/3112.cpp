#include <unordered_map>
#include <queue>

struct Solution {
    using pr = pair<int, int>;
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> res(n, -1);
        unordered_map<int, vector<pr>> edgeList;
        for (auto &e : edges){
            edgeList[e[0]].push_back({e[1], e[2]});
            edgeList[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<pr> h;
        h.push({0, 0});
        while (!h.empty()){
            auto [t, node] = h.top();
            h.pop();
            if (res[node] != -1){
                continue;
            }
            res[node] = -t;
            for (auto [nb, w] : edgeList[node]){
                if (res[nb] == -1 && disappear[nb] > w - t){
                    h.push({t - w, nb});
                }
            }
        }
        return res;
    }
};
