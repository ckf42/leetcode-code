struct Solution {
    int minimumPushes(string &word) {
        array<int, 26> freq = {0};
        for (char c : word){
            ++freq[c - 'a'];
        }
        ranges::sort(freq, std::greater<int>{});
        int res = 0;
        for (int i = 0; i < 26; ++i){
            res += ((i >> 3) + 1) * freq[i];
        }
        return res;
    }
};
