struct Solution {
    inline bool isPal(int i, int j, string &s){
        while (i < j){
            if (s[i] != s[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    void genpal(int idx, string &s, vector<string> &part, vector<vector<string>> &res){
        if (idx == s.size()){
            res.push_back(part);
            return;
        }
        for (int i = idx; i < s.size(); ++i){
            if (!this->isPal(idx, i, s)){
                continue;
            }
            part.push_back(s.substr(idx, i - idx + 1));
            this->genpal(i + 1, s, part, res);
            part.pop_back();
        }
    }
    vector<vector<string>> partition(string &s) {
        vector<vector<string>> res;
        vector<string> part;
        this->genpal(0, s, part, res);
        return res;
    }
};
