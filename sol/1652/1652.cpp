struct Solution {
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0){
            return res;
        }
        int e = k;
        if (k > 0){
            for (int i = 1; i <= k; ++i){
                res[0] += code[i];
            }
            for (int i = 1; i < n; ++i){
                res[i] = res[i - 1] - code[i] + code[(++e) % n];
            }
        } else {
            k = -k;
            for (int i = 1; i <= k; ++i){
                res[0] += code[n - i];
            }
            for (int i = 1; i < n; ++i){
                res[i] = res[i - 1] + code[i - 1] - code[(n + (e++)) % n];
            }
        }
        return res;
    }
};
