struct Solution {
    using ll = long long;
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        int n = nums.size();
        int s = n, e = n;
        ll res = 0;
        const auto b = nums.begin();
        for (int i = 0; i < n; ++i){
            s = lower_bound(b + i + 1, b + s, lower - nums[i]) - b;
            e = upper_bound(b + i, b + e, upper - nums[i]) - b;
            if (e <= i){
                break;
            }
            res += e - s;
        }
        return res;
    }
};
