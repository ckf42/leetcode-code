struct Solution {
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        for (auto &r : roads){
            ++deg[r[0]];
            ++deg[r[1]];
        }
        sort(deg.begin(), deg.end());
        long long res = 0;
        for (long long i = 0; i < n; ++i){
            res += (i + 1) * deg[i];
        }
        return res;
    }
};
