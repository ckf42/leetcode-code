#include <unordered_map>

struct Solution {
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> memo;
        for (int x : arr){
            memo[x] = memo[x - difference] + 1;
        }
        int res = 0;
        for (auto &pr : memo){
            res = max(res, pr.second);
        }
        return res;
    }
};
