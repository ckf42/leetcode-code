struct Solution {
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), q = queries.size();
        vector<int> qOrd(q), res(q);
        ranges::iota(qOrd, 0);
        ranges::sort(items, [&](vector<int> &i, vector<int> &j){return i[0] < j[0];});
        ranges::sort(qOrd, [&](int i, int j){return queries[i] < queries[j];});
        int itemIdx = 0, maxBeauty = 0;
        for (int qIdx : qOrd){
            while (itemIdx < n && items[itemIdx][0] <= queries[qIdx]){
                maxBeauty = max(maxBeauty, items[itemIdx++][1]);
            }
            res[qIdx] = maxBeauty;
        }
        return res;
    }
};
