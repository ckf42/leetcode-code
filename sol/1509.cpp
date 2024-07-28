#include <algorithm>

struct Solution {
    inline int minDifference(vector<int>& nums) {
        if (nums.size() <= 4){
            return 0;
        }
        int smallest[4], largest[4];
        std::partial_sort_copy(nums.begin(), nums.end(), smallest, smallest + 4);
        std::partial_sort_copy(nums.begin(), nums.end(), largest, largest + 4, std::greater<int>());
        return min(
            largest[3] - smallest[0],
            min(
                largest[2] - smallest[1],
                min(
                    largest[1] - smallest[2],
                    largest[0] - smallest[3]))
        );
    }
};
