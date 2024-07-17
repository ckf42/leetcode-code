struct Solution {
    inline string decodeCiphertext(string &encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 1 || n == 0){
            return encodedText;
        }
        int rowlen = n / rows;
        string res;
        for (int i = 0; i < rowlen; ++i){
            for (int j = i; j < n; j += rowlen + 1){
                res.push_back(encodedText[j]);
            }
        }
        while (res.back() == ' '){
            res.pop_back();
        }
        return res;
    }
};
