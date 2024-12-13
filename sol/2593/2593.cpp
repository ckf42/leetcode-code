struct Solution {
    using ll = long long;
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);
        ranges::iota(indices, 0);
        ranges::stable_sort(indices, [&](int a, int b){return nums[a] < nums[b];});
        vector<bool> marked(n, false);
        ll score = 0;
        for (int i : indices){
            if (marked[i]){
                continue;
            }
            score += nums[i];
            if (i > 0){
                marked[i - 1] = true;
            }
            marked[i] = true;
            if (i < n - 1){
                marked[i + 1] = true;
            }
        }
        return score;
    }
};
