#include <algorithm>
#include <bit>

struct Solution {
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        res.resize(arr.size());
        for (size_t i = 0; i < arr.size(); ++i){
            res[i] = arr[i] + 10001 * popcount(static_cast<unsigned>(arr[i]));
        }
        sort(res.begin(), res.end());
        for (size_t i = 0; i < arr.size(); ++i){
            res[i] %= 10001;
        }
        return res;
    }
};
