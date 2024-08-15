struct Solution {
    inline int minimumDeletions(string &s) {
        int res = 0, b = 0;
        for (char c : s){
            if (c == 'b'){
                ++b;
            } else if (b != 0){
                --b;
                ++res;
            }
        }
        return res;
    }
};
