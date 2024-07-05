#include <unordered_map>

struct Solution {
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> c;
        for (int x : nums1){
            ++c[x];
        }
        vector<int> res;
        for (int x : nums2){
            if (c[x] > 0){
                res.push_back(x);
                --c[x];
            }
        }
        return res;
    }
};
