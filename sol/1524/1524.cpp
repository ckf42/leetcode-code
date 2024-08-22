struct Solution {
    static constexpr int m = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int memo[2] = {0, 0}, res = 0;
        for (int x : arr){
            ++memo[0];
            if (x & 1){
                swap(memo[0], memo[1]);
            }
            res = (res + memo[1]) % this->m;
        }
        return res;
    }
};
