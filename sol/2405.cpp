struct Solution {
    inline int partitionString(string &s) {
        int res = 1, h = 0;
        for (char c : s){
            int m = 1 << (c - 'a');
            if (h & m){
                ++res;
                h = 0;
            }
            h |= m;
        }
        return res;
    }
};
