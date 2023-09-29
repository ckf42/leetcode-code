struct Solution {
    string customSortString(const string& order, const string& s) {
        short counter[26] = {0};
        for (char c : s){
            ++counter[c - 'a'];
        }
        string res = "";
        for (char c : order){
            if (counter[c - 'a'] > 0){
                res += string(counter[c - 'a'], c);
                counter[c - 'a'] = 0;
            }
        }
        for (short i = 0; i < 26; ++i){
            if (counter[i] != 0){
                res += string(counter[i], i + 'a');
            }
        }
        return res;
    }
};
