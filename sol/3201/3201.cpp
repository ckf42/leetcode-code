struct Solution {
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2){
            return n;
        }
        int total = nums[0] & 1, count = 1;
        int prev = total;
        for (int i = 1; i < n; ++i){
            int x = nums[i] & 1;
            total += x;
            if (x != prev){
                ++count;
                prev = x;
            }
        }
        return ranges::max({total, n - total, count});
    }
};
