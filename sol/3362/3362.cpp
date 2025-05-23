struct Solution {
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size(), cumsum = 0, qptr = 0, count = 0;
        vector<int> diff(n + 1, 0), h;
        ranges::sort(queries, [&](const auto &a, const auto &b){return a[0] < b[0];});
        for (int i = 0; i < n; ++i){
            cumsum += diff[i];
            while (qptr < q && queries[qptr][0] <= i){
                h.push_back(queries[qptr++][1]);
                ranges::push_heap(h);
            }
            while (!h.empty() && cumsum < nums[i]){
                ranges::pop_heap(h);
                int r = h.back();
                h.pop_back();
                if (r >= i){
                    ++cumsum;
                    --diff[r + 1];
                    ++count;
                }
            }
            if (cumsum < nums[i]){
                return -1;
            }
        }
        return q - count;
    }
};
