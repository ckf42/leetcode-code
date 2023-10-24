#include <algorithm>

struct Solution {
    int maxArea(const vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxval = (r - l) * min(height.front(), height.back()),
            maxh = *max_element(height.cbegin(), height.cend());
        while (r - l > 1){
            if (height[l] < height[r]){
                ++l;
            } else {
                --r;
            }
            maxval = max(maxval, (r - l) * min(height[l], height[r]));
            if (maxval >= maxh * (r - l)){
                break;
            }
        }
        return maxval;
    }
};
