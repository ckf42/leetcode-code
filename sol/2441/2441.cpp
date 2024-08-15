#include <unordered_map>

struct Solution {
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> exists;
        int maxval = -1;
        for (int &n : nums){
            exists[abs(n)] |= (n > 0 ? 1 : 2);
            n = abs(n);
            if (exists[n] == 3){
                maxval = max(maxval, n);
            }
        }
        return maxval;
    }
};
