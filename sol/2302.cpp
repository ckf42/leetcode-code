struct Solution {
    using ll = long long;
    long long countSubarrays(vector<int>& nums, long long k) {
        ll res = 0, partSum = 0;
        int s = 0, n = nums.size();
        for (int e = 0; e < n; ++e){
            partSum += nums[e];
            while (partSum * (e - s + 1) >= k){
                partSum -= nums[s++];
            }
            res += e - s + 1;
        }
        return res;
    }
};
