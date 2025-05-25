struct Solution {
    int longestPalindrome(vector<string>& words) {
        int freq[26][26] = {0}, res = 0;
        for (auto &w : words){
            ++freq[w[0] - 'a'][w[1] - 'a'];
        }
        bool hasSym = false;
        for (int i = 0; i < 26; ++i){
            for (int j = i + 1; j < 26; ++j){
                res += min(freq[i][j], freq[j][i]) * 4;
            }
            res += (freq[i][i] / 2) * 4;
            if (freq[i][i] & 1){
                hasSym = true;
            }
        }
        if (hasSym){
            res += 2;
        }
        return res;
    }
};
