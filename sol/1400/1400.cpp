struct Solution {
    bool canConstruct(string &s, int k) {
        if (s.size() < k){
            return false;
        }
        int counter[26] = {0};
        for (char c : s){
            ++counter[c - 'a'];
        }
        int exceptCount = 0;
        for (int i = 0; i < 26; ++i){
            exceptCount += (counter[i] & 1);
        }
        return exceptCount <= k;
    }
};
