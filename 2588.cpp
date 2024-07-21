#include <unordered_map>

struct Solution {
    long long beautifulSubarrays(vector<int>& nums) {
        long long res = 0;
        int prefix = 0;
        unordered_map<int, int> h;
        h[0] = 1;
        for (int x : nums){
            prefix ^= x;
            res += h[prefix]++;
        }
        return res;
    }
};
