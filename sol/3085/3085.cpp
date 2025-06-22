struct Solution {
    int minimumDeletions(string_view word, int k) {
        array<int, 26> freq = {0};
        for (char c : word){
            ++freq[c - 'a'];
        }
        ranges::sort(freq);
        int res = word.size();
        int prefix = 0, suffix = res, s = 0;
        while (s < 26 && freq[s] == 0){
            ++s;
        }
        int e = s;
        for (; s < 26; ++s){
            while (e < 26 && freq[e] <= freq[s] + k){
                suffix -= freq[e++];
            }
            res = min(
                res, 
                prefix + suffix - (26 - e) * (freq[s] + k)
            );
            prefix += freq[s];
        }
        return res;
    }
};
