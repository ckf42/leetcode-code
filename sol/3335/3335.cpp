struct Solution {
    static constexpr int M = 1e9 + 7;
    int lengthAfterTransformations(const string &s, int t) {
        int freq[26] = {0};
        for (char c : s){
            ++freq[c - 'a'];
        }
        int zptr = 25;
        while (t-- > 0){
            int zz = (zptr + 1) % 26;
            freq[zz] = (freq[zz] + freq[zptr]) % this->M;
            zptr = (zptr + 25) % 26;
        }
        int res = 0;
        for (int i = 0; i < 26; ++i){
            res = (res + freq[i]) % this->M;
        }
        return res;
    }
};
