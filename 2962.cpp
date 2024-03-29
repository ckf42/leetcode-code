#include <algorithm>

struct Solution {
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), maxele = *max_element(nums.begin(), nums.end()), e = 0, subCount = 0;
        long long res = 0;
        for (int s = 0; s < n; ++s){
            while (e < n && subCount < k){
                subCount += nums[e++] == maxele;
            }
            if (subCount < k){
                break;
            }
            res += n - e + 1;
            subCount -= nums[s] == maxele;
        }
        return res;
    }
};
