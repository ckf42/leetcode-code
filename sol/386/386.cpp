struct Solution {
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int val = 1;
        for (int i = 0; i < n; ++i){
            res[i] = val;
            if (val * 10 <= n){
                val *= 10;
            } else {
                while (val % 10 == 9 || val + 1 > n){
                    val /= 10;
                }
                ++val;
            }
        }
        return res;
    }
};
