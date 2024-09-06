struct Solution {
    inline static int f(string &s) {
        char c = '~';
        int freq = 0;
        for (char x : s){
            if (x < c){
                c = x;
                freq = 1;
            } else if (x == c){
                ++freq;
            }
        }
        return freq;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int> refFreq(n), res(queries.size());
        ranges::transform(words, refFreq.begin(), this->f);
        ranges::sort(refFreq);
        ranges::transform(queries, res.begin(), [&](string &q){
            return n - ranges::distance(refFreq.begin(), ranges::upper_bound(refFreq, this->f(q)));
        });
        return res;
    }
};
