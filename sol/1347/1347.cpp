struct Solution {
    int minSteps(const string &s, const string &t) {
        int count[26] = {0};
        for (char c : s){
            ++count[c - 'a'];
        }
        for (char c : t){
            --count[c - 'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i){
            res += abs(count[i]);
        }
        return res / 2;
    }
};
