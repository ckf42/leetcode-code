#include <unordered_set>

struct Solution {
    int repeatedNTimes(const vector<int>& nums) {
        unordered_set<int> s;
        for (const int n: nums){
            if (s.find(n) == s.end()){
                s.insert(n);
            } else {
                return n;
            }
        }
        return 0;
    }
};
