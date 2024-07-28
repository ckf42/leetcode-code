struct Solution {
    inline int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0, target = tickets[k];
        for (int i = 0; i <= k; ++i){
            res += min(target, tickets[i]);
        }
        --target;
        for (int i = k + 1; i < tickets.size(); ++i){
            res += min(target, tickets[i]);
        }
        return res;
    }
};
