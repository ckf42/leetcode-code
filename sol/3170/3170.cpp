struct Solution {
    string clearStars(string_view s) {
        int n = s.size();
        vector<bool> keep(n, true);
        vector<int> indices[26];
        int len[26] = {0};
        vector<short> h;
        for (int i = 0; i < n; ++i){
            if (s[i] == '*'){
                keep[i] = false;
                ranges::pop_heap(h);
                short c = -h.back();
                h.pop_back();
                keep[indices[c][--len[c]]] = false;
            } else {
                short v = s[i] - 'a';
                if (indices[v].size() == len[v]) {
                    indices[v].push_back(i);
                    ++len[v];
                } else {
                    indices[v][len[v]++] = i;
                }
                h.push_back(-v);
                ranges::push_heap(h);
            }
        }
        string res;
        for (int i = 0; i < n; ++i){
            if (keep[i]){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
