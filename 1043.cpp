struct Solution {
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> memo(arr.size(), 0);
        memo[0] = arr[0];
        int maxEle;
        for (int i = 0; i < arr.size(); ++i){
            maxEle = 0;
            for (int s = i; s >= max(0, i - k + 1); --s){
                maxEle = max(maxEle, arr[s]);
                memo[i] = max(memo[i], (s >= 1 ? memo[s - 1] : 0) + (i - s + 1) * maxEle);
            }
        }
        return memo.back();
    }
};
