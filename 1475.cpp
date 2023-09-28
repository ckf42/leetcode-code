struct Solution {
    vector<int> finalPrices(const vector<int>& prices) {
        size_t n = prices.size(), ptr;
        short i;
        vector<int> res, smallIdxAfter;
        res.resize(n);
        smallIdxAfter.resize(n);
        res[n - 1] = prices[n - 1];
        smallIdxAfter[n - 1] = n;
        for (i = n - 2; i >= 0; --i){
            ptr = i + 1;
            while (ptr < n && prices[i] < prices[ptr]){
                ptr = smallIdxAfter[ptr];
            }
            smallIdxAfter[i] = ptr;
            if (ptr == n){
                res[i] = prices[i];
            } else {
                res[i] = prices[i] - prices[smallIdxAfter[i]];
            }
        }
        return res;
    }
};
