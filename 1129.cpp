#include <unordered_map>
#include <queue>

struct Solution {
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> rEdgeList, bEdgeList;
        for (auto &e : redEdges){
            rEdgeList[e[0]].push_back(e[1]);
        }
        for (auto &e : blueEdges){
            bEdgeList[e[0]].push_back(e[1]);
        }
        queue<int> q;
        queue<bool> stq;
        q.push(0); q.push(0); stq.push(false);
        q.push(0); q.push(0); stq.push(true);
        vector<int> rDist(n, -1), bDist(n, -1);
        while (!q.empty()){
            int d = q.front(); q.pop();
            int node = q.front(); q.pop();
            bool isRed = stq.front(); stq.pop();
            if (isRed ? (rDist[node] != -1) : (bDist[node] != -1)){
                continue;
            }
            if (isRed){
                rDist[node] = d;
                for (int v : bEdgeList[node]){
                    if (bDist[v] == -1){
                        q.push(d + 1);
                        q.push(v);
                        stq.push(false);
                    }
                }
            } else {
                bDist[node] = d;
                for (int v : rEdgeList[node]){
                    if (rDist[v] == -1){
                        q.push(d + 1);
                        q.push(v);
                        stq.push(true);
                    }
                }
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i){
            if (rDist[i] == -1){
                res[i] = bDist[i];
            } else if (bDist[i] == -1){
                res[i] = rDist[i];
            } else {
                res[i] = min(rDist[i], bDist[i]);
            }
        }
        return res;
    }
};
