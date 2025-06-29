struct Solution {
    int numSubseq(vector<int>& nums, int target) {
        constexpr int M = 1e9 + 7;
        int n = nums.size(), res = 0;
        vector<int> power(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; ++i){
            power[i] = (power[i - 1] * 2) % M;
        }
        ranges::sort(nums);
        int r = n - 1;
        for (int l = 0; l < n; ++l){
            while (r >= l && nums[l] + nums[r] > target){
                --r;
            }
            if (r < l){
                break;
            }
            res = (res + power[r - l]) % M;
        }
        return res;
    }
};
