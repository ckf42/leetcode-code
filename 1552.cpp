struct Solution {
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size(), l = 1, r = position.back() - position.front() + 1;
        while (l < r){
            int p = l + (r - l) / 2, last = 0, placed = 1;
            for (int i = 1; placed < m && i < n; ++i){
                if (position[i] >= position[last] + p){
                    ++placed;
                    last = i;
                }
            }
            if (placed == m){
                l = p + 1;
            } else {
                r = p;
            }
        }
        return r - 1;
    }
};
