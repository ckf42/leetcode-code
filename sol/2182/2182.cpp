struct Solution {
    string repeatLimitedString(const string &s, int repeatLimit) {
        int freq[26] = {0};
        for (char c : s){
            ++freq[c - 'a'];
        }
        vector<pair<char, int>> st;
        for (int i = 0; i < 26; ++i){
            if (freq[i] != 0){
                st.push_back({'a' + i, freq[i]});
            }
        }
        string res = "";
        while (!st.empty()){
            auto [c, f] = st.back();
            st.pop_back();
            int take = min(f, repeatLimit);
            res.append(take, c);
            f -= take;
            if (f != 0 && !st.empty()){
                auto [cc, ff] = st.back();
                st.pop_back();
                res += cc;
                if (ff != 1){
                    st.push_back({cc, ff - 1});
                }
                st.push_back({c, f});
            }
        }
        return res;
    }
};
