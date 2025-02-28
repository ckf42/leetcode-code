#include <unordered_map>

struct Solution {
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> h;
        for (int i = 0; i < n; ++i){
            h[arr[i]] = i;
        }
        vector<vector<int>> memo(n, vector<int>(n, 2));
        int res = 2;
        for (int k = 2; k < n; ++k){
            for (int j = 1; j < k; ++j){
                int val = arr[k] - arr[j];
                if (val < arr[j] && h.contains(val)){
                    memo[j][k] = memo[h[val]][j] + 1;
                    res = max(res, memo[j][k]);
                }
            }
        }
        return (res == 2 ? 0 : res);
    }
};
