struct Solution {
    bool isValidPart(const string& s){
        size_t sSize = s.size();
        if (sSize == 0 || sSize > 3){
            return false;
        }
        if (s[0] == '0'){
            return (sSize == 1);
        }
        int sint = stoi(s);
        return (0 < sint && sint <= 255);
    }
    void recur(const string& s,
               unsigned short ptsToAdd,
               const string& current,
               vector<string>& res){
        if (ptsToAdd == 0){
            if (this->isValidPart(s)){
                res.push_back(current + s);
            }
            return;
        }
        size_t sSize = s.size();
        if (sSize < ptsToAdd + 1){
            return;
        }
        for (size_t l = 1; l <= sSize - ptsToAdd; ++l){
            string ss = s.substr(0, l);
            if (this->isValidPart(ss)){
                this->recur(s.substr(l, string::npos),
                            ptsToAdd - 1,
                            current + ss + ".",
                            res);
            }
        }
    }
    vector<string> restoreIpAddresses(const string& s) {
        vector<string> res;
        this->recur(s, 3, "", res);
        return res;
    }
};
