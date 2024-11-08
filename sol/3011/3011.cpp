#include <numeric>

struct Solution {
    bool canSortArray(vector<int>& nums) {
        int lower = 0, rgMax = 0, rgBitCount = 0, bc;
        for (int x : nums){
            bc = popcount(static_cast<unsigned>(x));
            if (bc != rgBitCount){
                lower = rgMax;
                rgMax = x;
                rgBitCount = bc;
            }
            if (x < lower){
                return false;
            }
            rgMax = max(rgMax, x);
        }
        return true;
    }
};
