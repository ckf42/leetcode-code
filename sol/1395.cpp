struct Solution {
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res = 0;
        for (int j = 1; j < n - 1; ++j){
            int l = 0, r = 0;
            for (int i = 0; i < j; ++i){
                l += rating[i] < rating[j];
            }
            for (int i = j + 1; i < n; ++i){
                r += rating[i] > rating[j];
            }
            res += l * r + (j - l) * (n - 1 - j - r);
        }
        return res;
    }
};
