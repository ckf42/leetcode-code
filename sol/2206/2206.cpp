struct Solution {
    bool divideArray(vector<int>& nums) {
        int counter[501] = {0};
        for (int x : nums){
            ++counter[x];
        }
        for (int i = 0; i <= 500; ++i){
            if (counter[i] & 1){
                return false;
            }
        }
        return true;
    }
};
