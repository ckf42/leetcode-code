#include <unordered_map>

struct Solution {
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, distinct = 0, s = 0, emin = 0, emax = 0;
        unordered_map<int, int> count;
        while (emin < n && distinct != k){
            ++count[nums[emin]];
            if (count[nums[emin]] == 1){
                ++distinct;
            }
            ++emin;
        }
        emax = max(emax, emin);
        while (emax < n && count[nums[emax]] != 0){
            ++emax;
        }
        if (distinct != k){
            return res;
        }
        res += emax - emin + 1;
        for (int s = 0; s < n; ++s){
            --count[nums[s]];
            if (count[nums[s]] == 0){
                --distinct;
                while (emin < n && distinct != k){
                    ++count[nums[emin]];
                    if (count[nums[emin]] == 1){
                        ++distinct;
                    }
                    ++emin;
                }
                emax = max(emax, emin);
                while (emax < n && count[nums[emax]] != 0){
                    ++emax;
                }
            }
            if (distinct != k){
                break;
            }
            res += emax - emin + 1;
        }
        return res;
    }
};
