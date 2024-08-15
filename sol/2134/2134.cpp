struct Solution {
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), total = reduce(nums.begin(), nums.end());
        int count = reduce(nums.begin() + total, nums.end());
        int res = count;
        for (int s = 0, e = total; s < n - 1; ++s, e = (e + 1) % n){
            count += (nums[e] == 0) - (nums[s] == 0);
            res = min(res, count);
        }
        return res;
    }
};
