#include <queue>

struct Solution {
    using state = pair<int, pair<int, int>>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> edgeList(n);
        for (auto &edge : flights){
            edgeList[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<state, vector<state>, greater<state>> q;
        vector<int> visited(n);
        for (int i = 0; i < n; ++i){
            visited[i] = k + 1;
        }
        q.push({0, {src, 0}});
        while (!q.empty()){
            state st = q.top();
            int cost = st.first, node = st.second.first, stops = st.second.second;
            q.pop();
            if (node == dst){
                return cost;
            }
            if (stops >= visited[node] || stops == k + 1){
                continue;
            }
            visited[node] = stops;
            for (auto &pr : edgeList[node]){
                q.push({cost + pr.second, {pr.first, stops + 1}});
            }
        }
        return -1;
    }
};
