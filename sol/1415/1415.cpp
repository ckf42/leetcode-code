struct Solution {
    string getHappyString(int n, int k) {
        string res;
        int l = 1 << (--n);
        if (k > l * 3){
            return res;
        }
        int q = (--k) / l;
        k &= l - 1;
        res.push_back('a' + q);
        l >>= 1;
        while (n-- > 0){
            if (k & l){
                q = (q == 2) ? 1 : 2;
            } else {
                q = (q == 0) ? 1 : 0;
            }
            res.push_back('a' + q);
            l >>= 1;
        }
        return res;
    }
};
