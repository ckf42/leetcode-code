struct Solution {
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back(vector<int>(1, 1));
        for (int i = 0; i < numRows - 1; ++i){
            res.push_back(vector<int>(1, 1));
            for (size_t j = 0; j < res[i].size() - 1; ++j){
                res.back().push_back(res[i][j] + res[i][j + 1]);
            }
            res.back().push_back(1);
        }
        return res;
    }
};
