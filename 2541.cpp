struct Solution {
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if (k == 0){
            return nums1 == nums2 ? 0 : -1;
        }
        long long count = 0, tot = 0;
        for (int i = 0; i < n; ++i){
            int d = nums1[i] - nums2[i];
            if (d % k != 0){
                return -1;
            }
            int q = d / k;
            tot += q;
            if (q > 0){
                count += q;
            }
        }
        return tot == 0 ? count : -1;
    }
};
