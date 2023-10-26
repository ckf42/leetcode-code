#include <algorithm>
#include <unordered_map>

struct Solution {
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        constexpr int m = 1000000000 + 7;
        unordered_map<int, long long> dp;
        unordered_map<int, long long>::const_iterator it;
        for (const int c : arr){
            dp[c] = 1;
        }
        long long val, sum = 1;
        for (int i = 1; i < arr.size(); ++i){
            for (int j = 0; j < i; ++j){
                if (arr[j] > arr[i] / arr[j]){
                    break;
                }
                if (arr[i] % arr[j] == 0){
                    it = dp.find(arr[i] / arr[j]);
                    if (it != dp.end()){
                        long long val = (dp[arr[j]] * it->second) % m;
                        if (arr[j] != it->first){
                            val = (val * 2) % m;
                        }
                        dp[arr[i]] = (dp[arr[i]] + val) % m;
                    }
                }
            }
            sum = (sum + dp[arr[i]]) % m;
        }
        return static_cast<int>(sum);
    }
};
