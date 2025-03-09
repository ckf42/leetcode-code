struct Solution {
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), res = 0, count = 1;
        for (int i = 1; i < n + k - 1; ++i){
            if (colors[i % n] != colors[(i - 1) % n]){
                ++count;
            } else {
                count = 1;
            }
            if (count >= k){
                ++res;
            }
        }
        return res;
    }
};
