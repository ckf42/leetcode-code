#include <numeric>

struct Solution {
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size(), totalQual = 0;
        vector<int> sortedIdx(n);
        iota(sortedIdx.begin(), sortedIdx.end(), 0);
        ranges::sort(sortedIdx, [&](int i, int j){
            return static_cast<double>(wage[i]) / quality[i] < static_cast<double>(wage[j]) / quality[j]; });
        vector<int> h(k);
        for (int i = 0; i < k; ++i){
            h[i] = quality[sortedIdx[i]];
            totalQual += h[i];
        }
        double minCost = totalQual * static_cast<double>(wage[sortedIdx[k - 1]]) / quality[sortedIdx[k - 1]];
        make_heap(h.begin(), h.end());
        for (int i = k; i < n; ++i){
            int j = sortedIdx[i];
            totalQual += quality[j] - h[0];
            pop_heap(h.begin(), h.end());
            h[k - 1] = quality[j];
            push_heap(h.begin(), h.end());
            minCost = min(minCost, totalQual * (static_cast<double>(wage[j]) / quality[j]));
        }
        return minCost;
    }
};
