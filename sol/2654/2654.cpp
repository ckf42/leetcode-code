#include <numeric>

struct Solution {
    int minOperations(vector<int>& nums) {
        int n = nums.size(), nonone = 0;
        for (int x : nums){
            if (x != 1){
                ++nonone;
            }
        }
        if (nonone != n){
            return nonone;
        }
        int minLen = n, g = nums[0];
        for (int j = 1; j < n; ++j){
            g = gcd(g, nums[j]);
            if (g == 1){
                minLen = j + 1;
                break;
            }
        }
        if (g != 1){
            return -1;
        }
        for (int i = 1; i < n; ++i){
            g = nums[i];
            for (int j = i + 1; j < n; ++j){
                g = gcd(g, nums[j]);
                if (g == 1){
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen + n - 2;
    }
};
