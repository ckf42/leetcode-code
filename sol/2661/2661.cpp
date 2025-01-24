struct Solution {
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), k = arr.size();
        vector<int> rowIdx(k), colIdx(k);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                rowIdx[mat[i][j] - 1] = i;
                colIdx[mat[i][j] - 1] = j;
            }
        }
        vector<int> rowCount(m, 0), colCount(n, 0);
        for (int t = 0; t < k; ++t){
            if (++rowCount[rowIdx[arr[t] - 1]] == n){
                return t;
            }
            if (++colCount[colIdx[arr[t] - 1]] == m){
                return t;
            }
        }
        return -1;
    }
};
