struct Solution {
    static constexpr int modulus = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 1));
        int p = 1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                res[i][j] = p;
                grid[i][j] %= this->modulus;
                p = (p * grid[i][j]) % this->modulus;
            }
        }
        p = 1;
        for (int i = n - 1; i >= 0; --i){
            for (int j = m - 1; j >= 0; --j){
                res[i][j] = (res[i][j] * p) % this->modulus;
                p = (p * grid[i][j]) % this->modulus;
            }
        }
        return res;
    }
};
