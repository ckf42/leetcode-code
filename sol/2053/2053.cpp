#include <unordered_map>

struct Solution {
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        int w = 0;
        for (int i = 0; i < arr.size(); ++i){
            if (!freq.contains(arr[i])){
                arr[w++] = arr[i];
            }
            ++freq[arr[i]];
        }
        if (w < k){
            return "";
        }
        for (int i = 0; i < w; ++i){
            if (freq[arr[i]] == 1){
                --k;
            }
            if (k == 0){
                return arr[i];
            }
        }
        return "";
    }
};
