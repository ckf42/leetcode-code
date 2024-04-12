struct Solution {
    int trap(vector<int>& height) {
        int res= 0, l = 0, r = height.size() - 1, maxLeft = 0, maxRight = 0;
        while (l < r){
            maxLeft = max(maxLeft, height[l]);
            maxRight = max(maxRight, height[r]);
            if (maxLeft < maxRight){
                res += maxLeft - height[l];
                ++l;
            } else {
                res += maxRight - height[r];
                --r;
            }
        }
        return res;
    }
};
