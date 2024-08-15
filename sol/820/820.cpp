struct Solution {
    int minimumLengthEncoding(vector<string>& words) {
        for (auto &w : words){
            ranges::reverse(w);
        }
        ranges::sort(words);
        int res = words.back().size() + 1;
        for (int i = 0; i < words.size() - 1; ++i){
            if (!words[i + 1].starts_with(words[i])){
                res += words[i].size() + 1;
            }
        }
        return res;
    }
};
