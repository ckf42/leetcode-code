#include <algorithm>

struct Solution {
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for (size_t i = 1; i < arr.size(); ++i){
            if (arr[i] - arr[i - 1] != d){
                return false;
            }
        }
        return true;
    }
};
