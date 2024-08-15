#include <deque>

struct Solution {
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1){
            return vector<int>{0};
        }
        vector<vector<int>> adjList(n);
        vector<int> deg(n);
        for (auto &e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
            ++deg[e[0]];
            ++deg[e[1]];
        }
        deque<int> leafNodes;
        for (int i = 0; i < n; ++i){
            if (adjList[i].size() == 1){
                leafNodes.push_back(i);
            }
        }
        while (n > 2){
            int s = leafNodes.size();
            n -= s;
            while (s-- > 0){
                int leaf = leafNodes.front();
                leafNodes.pop_front();
                deg[leaf] = 0;
                for (int nb : adjList[leaf]){
                    if (deg[nb] == 0){
                        continue;
                    }
                    --deg[nb];
                    if (deg[nb] == 1){
                        leafNodes.push_back(nb);
                    }
                }
            }
        }
        return vector<int>(leafNodes.begin(), leafNodes.end());
    }
};
