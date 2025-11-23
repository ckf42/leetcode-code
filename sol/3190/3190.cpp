struct Solution {
    inline int minimumOperations(const vector<int>& nums) {
        return std::accumulate(
            nums.begin(),
            nums.end(),
            0,
            [](int a, int b){return a + (b % 3 != 0);}
        );
    }
};
