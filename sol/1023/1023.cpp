struct Solution {
    inline static bool match(string &q, string &patt){
        int j = 0;
        for (int i = 0; i < q.size(); ++i){
            if (j < patt.size() && patt[j] == q[i]){
                ++j;
            } else if (q[i] <= 'Z'){
                return false;
            }
        }
        return j == patt.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string &pattern) {
        int nq = queries.size(), n = pattern.size();
        vector<bool> res(nq);
        for (int i = 0; i < nq; ++i){
            res[i] = this->match(queries[i], pattern);
        }
        return res;
    }
};
