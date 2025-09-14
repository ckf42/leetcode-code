struct Solution {
    int maxFreqSum(string_view s) {
        int freq[26] = {0};
        for (char c : s){
            ++freq[c - 'a'];
        }
        int maxVowel = 0, maxConso = 0;
        for (int i = 0; i < 26; ++i){
            if ((1 << i) & 1065233){
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConso = max(maxConso, freq[i]);
            }
        }
        return maxVowel + maxConso;
    }
};
