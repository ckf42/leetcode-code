struct Solution {
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int l = -1, r = -1, idx = n - 1;
        for (int i = n - 2; i >= 0; --i){
            if (s[i] > s[idx]){
                idx = i;
            } else if (s[i] != s[idx]){
                l = i;
                r = idx;
            }
        }
        if (l != -1){
            swap(s[l], s[r]);
        }
        return stoi(s);
    }
};
