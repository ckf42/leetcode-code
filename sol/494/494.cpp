struct Solution {
    int findTargetSumWays(vector<int>& nums, int target) {
        std::array<int, 2001> freq = {0}, newFreq;
        freq[1000] = 1;
        for (int x : nums){
            newFreq.fill(0);
            for (int i = 0; i < 2001; ++i){
                if (i - x >= 0){
                    newFreq[i - x] += freq[i];
                }
                if (i + x < 2001){
                    newFreq[i + x] += freq[i];
                }
            }
            std::swap(freq, newFreq);
        }
        return freq[target + 1000];
    }
};
