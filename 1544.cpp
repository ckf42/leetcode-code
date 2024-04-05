struct Solution {
    string makeGood(string &s) {
        string res;
        for (char &c : s){
            if (res.size() == 0 || abs(c - res.back()) != 32){
                res.push_back(c);
            } else if (res.size() != 0){
                res.pop_back();
            }
        }
        return res;
    }
};
