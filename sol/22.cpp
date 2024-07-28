struct Solution {
    void gen(int rmOpen, int rmClose, string &prefix, vector<string> &res){
        if (rmOpen == 0 && rmClose == 0){
            res.push_back(prefix);
            return;
        }
        if (rmOpen > 0){
            prefix.push_back('(');
            this->gen(rmOpen - 1, rmClose + 1, prefix, res);
            prefix.pop_back();
        }
        if (rmClose > 0){
            prefix.push_back(')');
            this->gen(rmOpen, rmClose - 1, prefix, res);
            prefix.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string prefix;
        this->gen(n, 0, prefix, res);
        return res;
    }
};
