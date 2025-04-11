struct Solution {
    int minOperations(vector<int>& nums, int k) {
        bitset<101> seen;
        int count = 0;
        for (int x : nums){
            if (x < k){
                return -1;
            }
            if (x > k && !seen[x]){
                seen.set(x);
                ++count;
            }
        }
        return count;
    }
};
