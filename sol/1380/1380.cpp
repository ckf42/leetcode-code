struct Solution {
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> res;
        for (int i = 0; i < m; ++i){
            int idx = ranges::min_element(matrix[i]) - matrix[i].begin();
            bool valid = true;
            for (int ii = 0; ii < m; ++ii){
                if (matrix[ii][idx] > matrix[i][idx]){
                    valid = false;
                    break;
                }
            }
            if (valid){
                res.push_back(matrix[i][idx]);
            }
        }
        return res;
    }
};
