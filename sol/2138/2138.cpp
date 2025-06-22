struct Solution {
    vector<string> divideString(const string &s, int k, char fill) {
        int n = s.size();
        int q = n / k, r = n % k;
        vector<string> res;
        for (int i = 0; i < q; ++i){
            res.push_back(s.substr(i * k, k));
        }
        if (r != 0){
            res.push_back(s.substr(n - r) + string(k - r, fill));
        }
        return res;
    }
};
