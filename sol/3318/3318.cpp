struct Solution {
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res(n - k + 1, 0);
        unordered_map<int, int> freq;
        for (int i = 0; i < k - 1; ++i){
            ++freq[nums[i]];
        }
        for (int i = 0; i < n - k + 1; ++i){
            ++freq[nums[i + k - 1]];
            vector<pair<int, int>> h;
            for (auto [z, f] : freq){
                if (f == 0){
                    continue;
                }
                if (h.size() <= x){
                    h.push_back({-f, -z});
                } else {
                    h.back() = {-f, -z};
                }
                ranges::push_heap(h);
                if (h.size() > x){
                    ranges::pop_heap(h);
                }
            }
            int l = min(static_cast<size_t>(x), h.size());
            for (int j = 0; j < l; ++j){
                auto [f, z] = h[j];
                res[i] += z * f;
            }
            --freq[nums[i]];
        }
        return res;        
    }
};
