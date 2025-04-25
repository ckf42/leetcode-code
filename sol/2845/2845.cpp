#include <unordered_map>

struct Solution {
    using ll = long long;
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        ll res = 0;
        unordered_map<int, int> bins;
        bins[0] = 1;
        int count = 0;
        for (int x : nums){
            if (x % modulo == k){
                count = (count + 1) % modulo;
            }
            res += bins[(count + modulo - k) % modulo];
            ++bins[count];
        }
        return res;
    }
};
