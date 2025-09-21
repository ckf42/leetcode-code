#include <numeric>

struct Solution {
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        int g;
        for (int x : nums){
            while (!res.empty() && (g = std::gcd(x, res.back())) != 1){
                x = x / g * res.back();
                res.pop_back();
            }
            res.push_back(x);
        }
        return res;
    }
};
