struct Solution {
    inline int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size(), b = prices[0];
        for (int i = 1; i < n; ++i){
            b = min(b, prices[i]);
            res = max(res, prices[i] - b);
        }
        return res;
    }
};
