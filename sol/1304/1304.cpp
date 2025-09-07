struct Solution {
    vector<int> sumZero(int n) {
        if (n == 2){
            return {-1, 1};
        }
        vector<int> res(n);
        ranges::iota(res, 0);
        res[n - 1] = -(n - 1) * (n - 2) / 2;
        return res;
    }
};
