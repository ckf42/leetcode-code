struct Solution {
    using ll = long long;
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<ll> buff[2] = {vector<ll>(n, 0), vector<ll>(n, 0)};
        for (int j = 0; j < n; ++j){
            buff[0][j] = points[0][j];
        }
        for (int i = 1; i < m; ++i){
            ll opt = buff[0][0];
            buff[1][0] = opt + points[i][0];
            for (int j = 1; j < n; ++j){
                opt = max(opt - 1, buff[0][j]);
                buff[1][j] = opt + points[i][j];
            }
            opt = 0;
            for (int j = n - 2; j >= 0; --j){
                opt = max(opt, buff[0][j + 1]) - 1;
                buff[1][j] = max(buff[1][j], opt + points[i][j]);
            }
            swap(buff[0], buff[1]);
        }
        return *ranges::max_element(buff[0]);
    }
};
