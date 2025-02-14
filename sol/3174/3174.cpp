struct Solution {
    string clearDigits(const string &s) {
        string res;
        for (char c : s){
            if ('0' <= c && c <= '9'){
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
