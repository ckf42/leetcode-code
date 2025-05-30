#include <unordered_map>
#include <queue>

struct Solution {
    int largestPathValue(const string &colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indeg(n, 0);
        unordered_map<int, vector<int>> adjList;
        for (auto &e : edges){
            ++indeg[e[1]];
            adjList[e[0]].push_back(e[1]);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i){
            if (indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()){
            int s = q.size();
            while (s-- > 0){
                int x = q.front();
                q.pop();
                topo.push_back(x);
                for (int nb : adjList[x]){
                    if (--indeg[nb] == 0){
                        q.push(nb);
                    }
                }
            }
        }
        if (topo.size() != n){
            return -1;
        }
        vector<vector<int>> memo(n, vector<int>(26, 0));
        int res = 1;
        while (!topo.empty()){
            int i = topo.back();
            topo.pop_back();
            int ic = colors[i] - 'a';
            if (adjList[i].empty()){
                memo[i][ic] = 1;
            } else {
                for (int nb : adjList[i]){
                    for (int c = 0; c < 26; ++c){
                        memo[i][c] = max(memo[i][c], memo[nb][c] + (c == ic));
                        res = max(res, memo[i][c]);
                    }
                }
            }
        }
        return res;
    }
};
