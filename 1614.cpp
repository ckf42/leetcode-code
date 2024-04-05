struct Solution {
    inline int maxDepth(string &s) {
        int d = 0, res = 0;
        for (char &c : s){
            if (c == '('){
                res = max(res, ++d);
            } else if (c == ')'){
                --d;
            }
        }
        return res;
    }
};
