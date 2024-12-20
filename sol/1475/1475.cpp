struct Solution {
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n, 0), st(1, prices.back());
        res.back() = prices.back();
        for (int i = n - 2; i >= 0; --i){
            while (!st.empty() && st.back() > prices[i]){
                st.pop_back();
            }
            res[i] = prices[i] - (st.empty() ? 0 : st.back());
            st.push_back(prices[i]);
        }
        return res;
    }
};
