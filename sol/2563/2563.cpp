struct Solution {
    using ll = long long;
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        int n = nums.size();
        ll res = 0;
        int l = n, r = n - 1;
        for (int i = 0; i < n; ++i){
            l = max(l, i + 1);
            while (l > i + 1 && nums[i] + nums[l - 1] >= lower){
                --l;
            }
            while (r >= l && nums[i] + nums[r] > upper){
                --r;
            }
            if (r <= i){
                break;
            }
            res += r - l + 1;
        }
        return res;
    }
};
