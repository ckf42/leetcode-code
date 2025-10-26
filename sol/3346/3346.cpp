struct Solution {
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        ranges::sort(nums);
        int n = nums.size();
        vector<int> buff, prefix(1, 0);
        int prev = nums[0];
        for (int i = 1; i < n; ++i){
            int x = nums[i];
            if (x != prev){
                buff.push_back(prev);
                prefix.push_back(i);
                prev = x;
            }
        }
        buff.push_back(prev);
        prefix.push_back(n);
        int m = buff.size(), res = 0, e = 1, l = 0, r = 0;
        for (int i = 0; i < m; ++i){
            while (e < m && buff[e] - buff[i] <= k * 2){
                ++e;
            }
            res = max(res, min(prefix[e] - prefix[i], numOperations));
            while (l < i && buff[l] - buff[i] < -k){
                ++l;
            }
            while (r < m && buff[r] - buff[i] <= k){
                ++r;
            }
            int c = prefix[i + 1] - prefix[i];
            res = max(res, min(prefix[r] - prefix[l] - c, numOperations) + c);
        }
        return res;
    }
};
