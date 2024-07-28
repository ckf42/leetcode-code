struct Solution {
    using ll = long long;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        ll res = 0;
        if (k == 1){
            for (int i = 0; i < n; ++i){
                res = max(res, static_cast<ll>(nums1[i] * nums2[i]));
            }
            return res;
        }
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), 
                [&nums2](int i, int j){return nums2[i] > nums2[j];});
        vector<int> h(k);
        ll sumh = 0;
        for (int i = 0; i < k - 1; ++i){
            h[i] = -nums1[indices[i]];
            sumh -= h[i];
        }
        make_heap(h.begin(), h.end() - 1);
        res = (sumh + nums1[indices[k - 1]]) * nums2[indices[k - 1]];
        for (int i = k; i < n; ++i){
            int x = nums1[indices[i - 1]];
            h[k - 1] = -x;
            push_heap(h.begin(), h.end());
            pop_heap(h.begin(), h.end());
            sumh += x + h[k - 1];
            res = max(res, (sumh + nums1[indices[i]]) * nums2[indices[i]]);
        }
        return res;
    }
};
