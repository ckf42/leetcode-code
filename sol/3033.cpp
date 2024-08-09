struct Solution {
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int j = 0; j < n; ++j){
            vector<int> idx(0);
            int maxi = -1;
            for (int i = 0; i < m; ++i){
                maxi = max(maxi, matrix[i][j]);
                if (matrix[i][j] == -1){
                    idx.push_back(i);
                }
            }
            for (int i : idx){
                matrix[i][j] = maxi;
            }
        }
        return matrix;
    }
};
