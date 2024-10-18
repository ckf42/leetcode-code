#include <unordered_map>

struct Solution {
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> c;
        c[0] = 1;
        int target = 0;
        for (int x : nums){
            target |= x;
            unordered_map<int, int> newc(c);
            for (auto [k, v] : c){
                newc[k | x] += v;
            }
            swap(c, newc);
        }
        return c[target];
    }
};
