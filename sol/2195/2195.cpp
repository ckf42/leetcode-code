struct Solution {
    using ll = long long;
    long long minimalKSum(vector<int>& nums, int k) {
        ll res = static_cast<ll>(k) * (k + 1) / 2;
        ranges::sort(nums);
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            if (i != 0 && nums[i] == nums[i - 1]){
                continue;
            }
            if (nums[i] > k){
                break;
            }
            res += (++k) - nums[i];
        }
        return res;
    }
};
