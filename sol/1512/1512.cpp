struct Solution {
    int numIdenticalPairs(const vector<int>& nums) {
        short counter[101] = {0};
        for (int n : nums){
            ++counter[n];
        }
        unsigned sum = 0;
        for (short i = 1; i <= 100; ++i){
            if (counter[i] >= 2){
                sum += counter[i] * (counter[i] - 1) / 2;
            }
        }
        return sum;
    }
};
