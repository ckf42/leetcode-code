struct Solution {
    int minimumLength(string &s) {
        int count[26] = {0};
        for (char c : s){
            ++count[c - 'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i){
            if (count[i] != 0){
                res += 2 >> (count[i] & 1);
            }
        }
        return res;
    }
};
