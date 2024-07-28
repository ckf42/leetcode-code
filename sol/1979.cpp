struct Solution {
    int findGCD(const vector<int>& nums) {
        int maxv = nums[0];
        int minv = maxv, temp;
        size_t s = nums.size();
        for (size_t i = 1; i < s; ++i){
            temp = nums[i];
            maxv = max(maxv, temp);
            minv = min(minv, temp);
        }
        if (maxv == minv){
            return maxv;
        } else {
            while (minv != 0){
                temp = maxv;
                maxv = minv;
                minv = temp % minv;
            }
            return maxv;
        }
    }
};
