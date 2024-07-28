#include <unordered_map>

struct Solution {
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> m;
        for (int x : nums1){
            m[x] |= 1;
        }
        for (int x : nums2){
            m[x] |= 2;
        }
        for (int x : nums3){
            m[x] |= 4;
        }
        vector<int> res;
        for (auto &x : m){
            if (x.second != 4 && x.second >= 3){
                res.push_back(x.first);
            }
        }
        return res;
    }
};
