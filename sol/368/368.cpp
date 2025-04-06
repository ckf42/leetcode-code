struct Solution {
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);
        vector<int> chainLen(n, 1), prevIdx(n, -1);
        int maxLen = 0, maxIdx = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (nums[j] % nums[i] != 0){
                    continue;
                }
                if (chainLen[j] < chainLen[i] + 1){
                    chainLen[j] = chainLen[i] + 1;
                    prevIdx[j] = i;
                    if (chainLen[j] > maxLen){
                        maxLen = chainLen[j];
                        maxIdx = j;
                    }
                }
            }
        }
        vector<int> res;
        while (maxIdx != -1){
            res.push_back(nums[maxIdx]);
            maxIdx = prevIdx[maxIdx];
        }
        return res;
    }
};
