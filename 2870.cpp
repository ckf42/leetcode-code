#include <unordered_map>

struct Solution {
    int minOperations(const vector<int>& nums) {
        unordered_map<int, int> c;
        for (int n : nums){
            ++c[n];
        }
        int res = 0;
        for (auto it = c.begin(); it != c.end(); ++it){
            if (it->second == 1){
                return -1;
            }
            res += (it->second + 2) / 3;
        }
        return res;
    }
};
