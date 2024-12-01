#include <unordered_map>

struct Solution {
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> edges;
        unordered_map<int, int> deg;
        for (auto &e : pairs){
            edges[e[1]].push_back(e[0]);
            --deg[e[0]];
            ++deg[e[1]];
        }
        vector<int> buff, path;
        for (auto &pr : deg){
            if (pr.second == 1){
                buff.push_back(pr.first);
                break;
            }
        }
        if (buff.empty()){
            buff.push_back(pairs[0][0]);
        }
        vector<vector<int>> res;
        int prev = -1;
        while (!buff.empty()){
            int node = buff.back();
            if (edges[node].empty()){
                if (prev != -1){
                    res.push_back({prev, node});
                }
                prev = node;
                buff.pop_back();
            } else {
                buff.push_back(edges[node].back());
                edges[node].pop_back();
            }
        }
        return res;
    }
};
