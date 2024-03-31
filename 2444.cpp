struct Solution {
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int lastMinK = -1, lastMaxK = -1, lastOb = -1;
        for (int e = 0; e < nums.size(); ++e){
            if (minK > nums[e] || nums[e] > maxK){
                lastOb = e;
            } else {
                if (nums[e] == minK){
                    lastMinK = e;
                }
                if (nums[e] == maxK){
                    lastMaxK = e;
                }
                res += max(0, min(lastMinK, lastMaxK) - lastOb);
            }
        }
        return res;
    }
};
