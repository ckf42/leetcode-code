struct Solution {
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix.front().size(), w = 0;
        vector<int> v(m * n);
        v[w++] = matrix[0][0];
        for (int j = 1; j < n; ++j){
            matrix[0][j] ^= matrix[0][j - 1];
            v[w++] = matrix[0][j];
        }
        for (int i = 1; i < m; ++i){
            matrix[i][0] ^= matrix[i - 1][0];
            v[w++] = matrix[i][0];
        }
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
                v[w++] = matrix[i][j];
            }
        }
        ranges::nth_element(v, v.begin() + k - 1, std::greater{});
        return v[k - 1];
    }
};
