#include <algorithm>

struct Solution {
    int getWinner(const vector<int>& arr, int k) {
        if (k >= arr.size() - 1){
            return *max_element(arr.cbegin(), arr.cend());
        } else if (k == 1) {
            return max(arr[0], arr[1]);
        }
        int headPtr = 0, winCount = 0;
        for (int i = 1; i < arr.size(); ++i){
            if (arr[headPtr] > arr[i]){
                if (++winCount == k){
                    return arr[headPtr];
                }
            } else {
                headPtr = i;
                winCount = 1;
            }
        }
        return arr[headPtr];
    }
};
