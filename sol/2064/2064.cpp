struct Solution {
    int required(int k, vector<int> &quantities, int m){
        int res = 0;
        for (int i = 0; i < m; ++i){
            if (quantities[i] <= k){
                return res + m - i;
            }
            res += (quantities[i] + k - 1) / k;
        }
        return res;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        ranges::sort(quantities, std::greater{});
        int s = 1, e = quantities[0];
        while (s < e){
            int k = (s + e) / 2;
            if (this->required(k, quantities, m) > n){
                s = k + 1;
            } else {
                e = k;
            }
        }
        return s;
    }
};
