#include <unordered_map>

struct Solution {
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> d;
        d[0] = 1;
        int prefix = 0, res = 0;
        for (int &x : nums){
            prefix = ((prefix + x) % k + k) % k;
            res += d[prefix]++;
        }
        return res;
    }
};
