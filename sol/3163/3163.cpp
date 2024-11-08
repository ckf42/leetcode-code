struct Solution {
    string compressedString(string &word) {
        string res;
        int n = word.size(), i = 0;
        while (i < n){
            int j = i + 1;
            while (j < n && word[j] == word[i] && j - i < 9){
                ++j;
            }
            res.push_back('0' + j - i);
            res.push_back(word[i]);
            i = j;
        }
        return res;
    }
};
