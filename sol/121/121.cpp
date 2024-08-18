struct Solution {
    inline int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size(), b = prices[0];
        for (int i = 1; i < n; ++i){
            if (prices[i] < b){
                b = prices[i];
            } else {
                res = max(res, prices[i] - b);
            }
        }
        return res;
    }
};
