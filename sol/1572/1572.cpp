struct Solution {
    int diagonalSum(const vector<vector<int>>& mat) {
        size_t n = mat.size();
        int tot = 0;
        for (size_t i = 0; i < n; ++i){
            tot += mat[i][i] + mat[i][n - 1 - i];
        }
        if (n & 1){
            tot -= mat[n / 2][n / 2];
        }
        return tot;
    }
};
