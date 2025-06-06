struct Solution {
    string robotWithString(string_view s) {
        int n = s.size();
        vector<int> smallest(n, n - 1);
        for (int i = n - 2; i >= 0; --i){
            smallest[i] = smallest[i + 1];
            if (s[i] <= s[smallest[i]]){
                smallest[i] = i;
            }
        }
        string t, res;
        int ptr = 0;
        while (ptr < n){
            while (smallest[ptr] != ptr){
                t.push_back(s[ptr++]);
            }
            res.push_back(s[ptr++]);
            if (ptr == n){
                break;
            }
            char c = s[smallest[ptr]];
            while (!t.empty() && t.back() <= c){
                res.push_back(t.back());
                t.pop_back();
            }
        }
        res.insert(res.end(), t.rbegin(), t.rend());
        return res;
    }
};
