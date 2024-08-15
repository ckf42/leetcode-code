struct Solution {
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (size_t i = 1; i <= rowIndex; ++i){
            res[i] = res[i - 1] * (rowIndex + 1 - i) / i;
        }
        return res;
    }
};
