struct Solution {
    constexpr static short diff = 'a' - 'A';
    vector<string> letterCasePermutation(const string &s) {
        if (s.size() == 0){
            return vector<string>{""};
        } else {
            vector<string> res, newRes = this->letterCasePermutation(s.substr(1));
            for (const string &ss : newRes){
                res.push_back(s[0] + ss);
                if (s[0] >= 'a'){
                    res.push_back(static_cast<char>(s[0] - diff) + ss);
                } else if (s[0] >= 'A'){
                    res.push_back(static_cast<char>(s[0] + diff) + ss);
                }
            }
            return res;
        }
    }
};
