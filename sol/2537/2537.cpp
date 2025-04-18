#include <unordered_map>

struct Solution {
    using ll = long long;
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        ll res = 0, count = 0;
        unordered_map<int, int> seen;
        for (int r = 0; r < n; ++r){
            count += seen[nums[r]]++;
            while (count >= k){
                count -= --seen[nums[l++]];
            }
            res += l;
        }
        return res;
    }
};
