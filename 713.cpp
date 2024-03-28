struct Solution {
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, prod = 1, s = 0;
        for (int e = 0; e < nums.size(); ++e){
            prod *= nums[e];
            while (s <= e && prod >= k){
                prod /= nums[s++];
            }
            res += e - s + 1;
        }
        return res;
    }
};
