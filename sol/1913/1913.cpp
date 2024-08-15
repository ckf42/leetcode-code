struct Solution {
    int maxProductDifference(vector<int>& nums) {
        make_heap(nums.begin(), nums.end());
        pop_heap(nums.begin(), nums.end());
        int largeProd = nums.back();
        nums.pop_back();
        pop_heap(nums.begin(), nums.end());
        largeProd *= nums.back();
        nums.pop_back();
        make_heap(nums.begin(), nums.end(), greater<int>());
        pop_heap(nums.begin(), nums.end(), greater<int>());
        int smallProd = nums.back();
        nums.pop_back();
        pop_heap(nums.begin(), nums.end(), greater<int>());
        smallProd *= nums.back();
        return largeProd - smallProd;
    }
};
