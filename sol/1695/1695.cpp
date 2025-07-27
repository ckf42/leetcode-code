struct Solution {
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), res = 0, l = -1, total = 0;
        unordered_map<int, int> prevIdx;
        for (int i = 0; i < n; ++i){
            int x = nums[i];
            if (prevIdx.contains(x) && prevIdx[x] > l){
                for (int j = l + 1; j <= prevIdx[x]; ++j){
                    total -= nums[j];
                }
                l = prevIdx[x];
            }
            total += x;
            prevIdx[x] = i;
            res = max(res, total);
        }
        return res;
    }
};
