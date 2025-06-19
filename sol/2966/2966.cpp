struct Solution {
    using VVi = vector<vector<int>>;
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        VVi res;
        ranges::sort(nums);
        for (int i = 0; i < nums.size(); i += 3){
            if (nums[i + 2] - nums[i] > k){
                return VVi();
            }
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return res;
    }
};
