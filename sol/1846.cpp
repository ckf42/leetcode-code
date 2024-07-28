#include <algorithm>

struct Solution {
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int lastEle = 0;
        for (int &e : arr){
            lastEle = min(lastEle + 1, e);
        }
        return lastEle;
    }
};
