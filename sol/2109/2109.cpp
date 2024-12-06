struct Solution {
    string addSpaces(string &s, vector<int>& spaces) {
        int n = s.size(), ptr = 0, l = spaces.size(), wptr = 0;
        string res(n + l, 0);
        for (int i = 0; i < n; ++i){
            if (ptr < l && i == spaces[ptr]){
                res[wptr++] = ' ';
                ++ptr;
            }
            res[wptr++] = s[i];
        }
        return res;
    }
};
