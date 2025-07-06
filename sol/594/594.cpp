#include <unordered_map>

struct Solution {
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums){
            ++freq[x];
        }
        int res = 0;
        for (auto [a, f1] : freq){
            if (freq.contains(a + 1)){
                res = max(res, f1 + freq.at(a + 1));
            }
        }
        return res;
    }
};
