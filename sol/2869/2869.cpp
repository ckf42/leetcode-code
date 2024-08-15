struct Solution {
    int minOperations(const vector<int>& nums, int k) const {
        vector<bool> collected(k, false);
        short collectedCount = 0, curr = 1;
        for (vector<int>::const_reverse_iterator it = nums.crbegin();
             it != nums.crend();
             ++it, ++curr){
            if (*it <= k && !collected[*it - 1]){
                collected[*it - 1] = true;
                ++collectedCount;
                if (collectedCount == k){
                    return curr;
                }
            }
        }
        return -1;
    }
};
