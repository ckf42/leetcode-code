struct Solution {
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<double> r(n);
        for (int i = 0; i < n; ++i){
            r[i] = static_cast<double>(wage[i]) / quality[i];
        }
        vector<int> indices(n);
        ranges::iota(indices, 0);
        ranges::sort(indices, [&](int i, int j){return r[i] < r[j];});
        vector<int> h(k);
        for (int i = 0; i < k; ++i){
            h[i] = quality[indices[i]];
        }
        int totalQ = 0;
        for (int q : h){
            totalQ += q;
        }
        double minCost = r[indices[k - 1]] * totalQ;
        ranges::make_heap(h);
        for (int i = k; i < n; ++i){
            ranges::pop_heap(h);
            totalQ += quality[indices[i]] - h.back();
            minCost = min(minCost, r[indices[i]] * totalQ);
            h.back() = quality[indices[i]];
            ranges::push_heap(h);
        }
        return minCost;
    }
};
