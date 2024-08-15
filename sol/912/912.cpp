struct Solution {
    static constexpr int offset = 50000;
    vector<int> sortArray(vector<int>& nums) {
        for (int msk = 0; msk < 5; ++msk){
            vector<int> buckets[16];
            for (int x : nums){
                buckets[((x + this->offset) >> (msk << 2)) & 15].push_back(x);
            }
            int w = 0;
            for (int b = 0; b < 16; ++b){
                for (int x : buckets[b]){
                    nums[w++] = x;
                }
            }
        }
        return nums;
    }
};
