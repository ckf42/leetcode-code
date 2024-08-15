struct Solution {
    string frequencySort(string &s) {
        int freq[62] = {0};
        for (char c : s){
            ++freq[c - '0' - 7 * (c >= 'A') - 6 * (c >= 'a')];
        }
        vector<int> indices;
        for (int i = 0; i < 62; ++i){
            if (freq[i] != 0){
                indices.push_back(i);
            }
        }
        sort(indices.begin(), indices.end(), [&freq](int a, int b){return freq[a] > freq[b];});
        string res;
        for (int idx : indices){
            res += string(freq[idx], '0' + idx + 7 * (idx >= 10) + 6 * (idx >= 36));
        }
        return res;
    }
};
