struct Solution {
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), res = 0, l = 0, typeCount = 0;
        vector<int> count(n, 0);
        for (int r = 0; r < n; ++r){
            if (++count[fruits[r]] == 1){
                ++typeCount;
            }
            while (typeCount > 2){
                if (--count[fruits[l++]] == 0){
                    --typeCount;
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
