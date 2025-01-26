struct Solution {
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> res(n), sortedIdx(n);
        ranges::iota(sortedIdx, 0);
        ranges::sort(sortedIdx, [&](int i, int j){return nums[i] < nums[j];});
        int s = 0;
        while (s < n){
            int e = s + 1;
            while (e < n && nums[sortedIdx[e]] - nums[sortedIdx[e - 1]] <= limit){
                ++e;
            }
            sort(sortedIdx.begin() + s, sortedIdx.begin() + e);
            vector<int> buff(e - s);
            for (int i = 0; i < e - s; ++i){
                buff[i] = nums[sortedIdx[s + i]];
            }
            ranges::sort(buff);
            for (int i = 0; i < e - s; ++i){
                res[sortedIdx[s + i]] = buff[i];
            }
            s = e;
        }
        return res;
    }
};
