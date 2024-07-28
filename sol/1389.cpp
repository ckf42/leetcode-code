#include <list>
#include <iterator>

struct Solution {
    vector<int> createTargetArray(const vector<int>& nums, const vector<int>& index) {
        size_t n = nums.size();
        list<int> l;
        list<int>::iterator it;
        for (size_t i = 0; i < n; ++i){
            if (index[i] == 0){
                l.push_front(nums[i]);
            } else {
                it = l.begin();
                advance(it, index[i]);
                l.insert(it, nums[i]);
            }
        }
        return vector<int>(l.begin(), l.end());
    }
};
