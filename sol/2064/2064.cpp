struct Solution {
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = ranges::max(quantities) + 1;
        while (l < r){
            int m = (l + r) / 2;
            int q = 0;
            for (int x : quantities){
                q += (x + m - 1) / m;
            }
            if (q <= n){
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
