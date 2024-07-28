struct Solution {
    int countHomogenous(const string &s) {
        int m = 1'000'000'007, res = 0, ptrl = 0, ptrr;
        long long n, comb;
        while (ptrl < s.size()){
            ptrr = ptrl + 1;
            while (ptrr < s.size() && s[ptrl] == s[ptrr]){
                ++ptrr;
            }
            n = ptrr - ptrl;
            if (n & 1){
                comb = (((n + 1) >> 1) * n) % m;
            } else {
                comb = ((n >> 1) * (n + 1)) % m;
            }
            res = (res + comb) % m;
            ptrl = ptrr;
        }
        return res;
    }
};
