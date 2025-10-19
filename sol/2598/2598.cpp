struct Solution {
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> count(value, 0);
        for (int x : nums){
            ++count[(x % value + value) % value];
        }
        int r = value, v = nums.size() + 1;
        for (int i = 0; i < value; ++i){
            if (count[i] < v){
                v = count[i];
                r = i;
            }
        }
        return v * value + r;
    }
};
