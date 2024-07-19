struct Solution {
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count[100] = {0}, res = 0;
        for (auto &dom : dominoes){
            int a = dom[0], b = dom[1];
            if (a > b){
                swap(a, b);
            }
            res += count[a * 10 + b]++;
        }
        return res;
    }
};
