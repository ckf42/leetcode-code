struct Solution {
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        ranges::iota(idx, 0);
        ranges::sort(idx, [&heights](int i, int j){return heights[i] > heights[j];});
        vector<string> res(n);
        for (int i = 0; i < n; ++i){
            res[i] = names[idx[i]];
        }
        return res;
    }
};
