struct Solution {
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> idx(n), res(n);
        ranges::iota(idx, 0);
        ranges::sort(idx, [&](int a, int b){return arr[a] < arr[b];});
        int rank = 0;
        for (int i = 0; i < n; ++i){
            if (i == 0 || arr[idx[i - 1]] != arr[idx[i]]){
                ++rank;
            }
            res[idx[i]] = rank;
        }
        return res;
    }
};
