struct Solution {
    int minIncrementForUnique(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        vector<int> freq(m + 1, 0);
        for (int &x : nums){
            ++freq[x];
        }
        int res = 0;
        for (int i = 0; i < m; ++i){
            if (freq[i] > 1){
                res += freq[i] - 1;
                freq[i + 1] += freq[i] - 1;
            }
        }
        res += freq[m] * (freq[m] - 1) / 2;
        return res;
    }
};
