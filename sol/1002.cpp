struct Solution {
    vector<string> commonChars(vector<string>& words) {
        int freq[26] = {0};
        for (char &c : words[0]){
            ++freq[c - 'a'];
        }
        for (int i = 1; i < words.size(); ++i){
            int buff[26] = {0};
            for (char &c : words[i]){
                ++buff[c - 'a'];
            }
            for (int c = 0; c < 26; ++c){
                freq[c] = min(freq[c], buff[c]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i){
            string target = string(1, i + 'a');
            for (int j = 0; j < freq[i]; ++j){
                res.push_back(target);
            }
        }
        return res;
    }
};
