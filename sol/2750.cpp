struct Solution {
    static constexpr int m = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int res = 1, prev = -1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] != 1){
                continue;
            }
            if (prev != -1){
                res = (static_cast<long>(res) * (i - prev)) % this->m;
            }
            prev = i;
        }
        return prev == -1 ? 0 : res;
    }
};
