#include <unordered_map>

struct Solution {
    inline int reverseNum(int val){
        int res = 0;
        while (val != 0){
            res *= 10;
            res += val % 10;
            val /= 10;
        }
        return res;
    }

    int countNicePairs(const vector<int>& nums) {
        constexpr int m = 1'000'000'007;
        unordered_map<int, int> counter;
        for (int n : nums){
            ++counter[n - this->reverseNum(n)];
        }
        int res = 0;
        for (const auto &[k, v] : counter){
            res += (static_cast<long>(v) * (v - 1) / 2) % m;
            res %= m;
        }
        return res;
    }
};
