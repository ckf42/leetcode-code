 struct Solution {
    long long maxKelements(vector<int>& nums, int k) {
        ranges::make_heap(nums);
        long long score = 0;
        while (k-- > 0){
            ranges::pop_heap(nums);
            score += nums.back();
            nums.back() += 2;
            nums.back() /= 3;
            ranges::push_heap(nums);
        }
        return score;
    }
};
