#include <queue>

struct Solution {
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(), totCount = 0;
        vector<int> ptrs(k, 1), arrCount(k, 0);
        vector<pair<int, int>> h(k);
        for (int i = 0; i < k; ++i){
            h[i] = make_pair(-nums[i][0], i);
        }
        ranges::make_heap(h);
        deque<pair<int, int>> q;
        int wl = -1e5, wr = 1e5;
        while (!h.empty()){
            ranges::pop_heap(h);
            auto [v, i] = h.back();
            h.pop_back();
            if (ptrs[i] != nums[i].size()){
                h.emplace_back(-nums[i][ptrs[i]++], i);
                ranges::push_heap(h);
            }
            q.emplace_back(-v, i);
            if (++arrCount[i] == 1){
                ++totCount;
            }
            while (!q.empty() && totCount == k && arrCount[q.front().second] != 1){
                --arrCount[q.front().second];
                q.pop_front();
            }
            if (totCount == k && q.back().first - q.front().first < wr - wl){
                wl = q.front().first;
                wr = q.back().first;
            }
        }
        return {wl, wr};
    }
};
