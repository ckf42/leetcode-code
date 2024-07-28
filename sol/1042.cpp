#include <unordered_map>

struct Solution {
    static inline int getColor(char mask) {
        if ((mask & 2) == 0){return 1;}
        if ((mask & 4) == 0){return 2;}
        if ((mask & 8) == 0){return 3;}
        if ((mask & 16) == 0){return 4;}
        return 0;  // should not reach
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> edgeList;
        for (auto &e : paths){
            edgeList[e[0] - 1].push_back(e[1] - 1);
            edgeList[e[1] - 1].push_back(e[0] - 1);
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i){
            char choice = 0;
            for (int &j : edgeList[i]){
                if (j < i){
                    choice |= (1 << res[j]);
                }
            }
            res[i] = this->getColor(choice);
        }
        return res;
    }
};
