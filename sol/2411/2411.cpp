struct Solution {
    vector<int> smallestSubarrays(vector<int>& nums) {
        std::array<int, 30> firstIdx;
        firstIdx.fill(-1);
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; --i){
            int x = nums[i], m = 1, idx = 0;
            while (x >= m){
                if (x & m){
                    firstIdx[idx] = i;
                }
                m <<= 1;
                ++idx;
            }
            res[i] = max(i, ranges::max(firstIdx)) - i + 1;
        }
        return res;
    }
};
