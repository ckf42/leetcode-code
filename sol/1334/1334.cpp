struct Solution {
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 100000));
        for (int i = 0; i < n; ++i){
            dist[i][i] = 0;
        }
        for (auto &e : edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; ++k){
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int count = n, res = 0;
        for (int i = 0; i < n; ++i){
            int currCount = 0;
            for (int j = 0; j < n; ++j){
                currCount += dist[i][j] <= distanceThreshold;
            }
            if (currCount <= count){
                count = currCount;
                res = i;
            }
        }
        return res;
    }
};
