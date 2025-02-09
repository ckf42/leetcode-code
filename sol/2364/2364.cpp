struct Solution {
    using ll = long long;
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            nums[i] -= i;
        }
        ranges::sort(nums);
        int s = 0, e;
        ll res = static_cast<ll>(n) * (n - 1) / 2;
        while (s < n){
            e = s + 1;
            while (e < n && nums[e] == nums[s]){
                ++e;
            }
            ll l = e - s;
            res -= l * (l - 1) / 2;
            s = e;
        }
        return res;
    }
};
