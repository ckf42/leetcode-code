#include <unordered_set>
#include <deque>

struct Solution {
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edgeList(n);
        vector<int> indeg(n, 0);
        for (auto &e : edges){
            edgeList[e[0]].push_back(e[1]);
            ++indeg[e[1]];
        }
        vector<unordered_set<int>> resSet(n);
        deque<int> lvl;
        for (int i = 0; i < n; ++i){
            if (indeg[i] == 0){
                lvl.push_back(i);
            }
        }
        while (!lvl.empty()){
            int x = lvl.front();
            lvl.pop_front();
            indeg[x] = -1;
            for (int nb : edgeList[x]){
                resSet[nb].insert(x);
                for (int y : resSet[x]){
                    resSet[nb].insert(y);
                }
                if (--indeg[nb] == 0){
                    lvl.push_back(nb);
                }
            }
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i){
            res[i].insert(res[i].begin(), resSet[i].begin(), resSet[i].end());
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};
