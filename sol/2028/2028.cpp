struct Solution {
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int residual = (m + n) * mean - reduce(rolls.begin(), rolls.end());
        if (residual > 6 * n || residual < n){
            return vector<int>();
        }
        int q = residual / n, r = residual % n;
        vector<int> res(n, q);
        for (int i = 0; i < r; ++i){
            ++res[i];
        }
        return res;
    }
};
