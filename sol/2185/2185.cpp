struct Solution {
    inline int prefixCount(vector<string>& words, string &pref) {
        int res = 0;
        for (auto &w : words){
            res += w.starts_with(pref);
        }
        return res;
    }
};
