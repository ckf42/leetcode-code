struct Solution {
    int maxProfitAssignment(const vector<int>& difficulty, const vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        int ptr = 0, n = profit.size(), maxP = 0, res = 0;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&difficulty](const int &a, const int &b) {
            return difficulty[a] < difficulty[b];
        });
        for (int &w : worker){
            while (ptr < n && difficulty[idx[ptr]] <= w){
                maxP = max(maxP, profit[idx[ptr++]]);
            }
            res += maxP;
        }
        return res;
    }
};
