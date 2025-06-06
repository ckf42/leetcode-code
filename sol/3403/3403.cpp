struct Solution {
    string answerString(const string &word, int numFriends) {
        if (numFriends == 1){
            return word;
        }
        int n = word.size();
        int l = n - numFriends + 1;
        auto wv = string_view(word), res = string_view();
        for (int i = 0; i < n; ++i){
            auto seg = wv.substr(i, l);
            if (seg > res){
                res = seg;
            }
        }
        return string(res);
    }
};
