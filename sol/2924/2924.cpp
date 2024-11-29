struct Solution {
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        for (auto &e : edges){
            ++indeg[e[1]];
        }
        int res = -1;
        for (int i = 0; i < n; ++i){
            if (indeg[i] == 0){
                if (res == -1){
                    res = i;
                } else {
                    return -1;
                }
            }
        }
        return res;
    }
};
