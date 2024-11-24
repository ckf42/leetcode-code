struct Solution {
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        bool hasSingleNeg = false;
        int minEle = abs(matrix[0][0]);
        for (auto &r : matrix){
            for (int x : r){
                if (x < 0){
                    hasSingleNeg = !hasSingleNeg;
                }
                x = abs(x);
                res += x;
                minEle = min(minEle, x);
            }
        }
        if (hasSingleNeg){
            res -= 2 * minEle;
        }
        return res;
    }
};
