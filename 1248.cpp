struct Solution {
    int atMostKOdd(const vector<int> &nums, const int k){
        if (k < 0){
            return 0;
        }
        int res = 0, oddCount = 0, s = 0;
        for (int e = 0; e < nums.size(); ++e){
            oddCount += nums[e] & 1;
            if (oddCount == k + 1){
                while ((nums[s] & 1) == 0){
                    ++s;
                }
                ++s;
                oddCount = k;
            }
            res += e - s + 1;
        }
        return res;
    }

    inline int numberOfSubarrays(vector<int>& nums, int k) {
        return this->atMostKOdd(nums, k) - this->atMostKOdd(nums, k - 1);
    }
};
