#include <unordered_map>

struct Solution {
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int remainder = 0;
        for (int x : nums){
            remainder = (remainder + x) % p;
        }
        if (remainder == 0){
            return 0;
        }
        unordered_map<int, int> d;
        d[0] = -1;
        int tot = 0, res = n, x;
        for (int i = 0; i < n; ++i){
            tot = (tot + nums[i]) % p;
            x = (tot - remainder + p) % p;
            if (d.contains(x)){
                res = min(res, i - d[x]);
            }
            d[tot] = i;
        }
        return res == n ? -1 : res;
    }
};
