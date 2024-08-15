struct Solution {
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::greater{});
        long long prefix = 0;
        for (int &x : nums){
            prefix += x;
        }
        for (int i = 0; i < nums.size() - 2; ++i){
            if ((nums[i] << 1) < prefix){
                return prefix;
            }
            prefix -= nums[i];
        }
        return -1;
    }
};
