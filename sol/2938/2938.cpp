struct Solution {
    long long minimumSteps(string &s) {
        int bcount = 0;
        long long res = 0;
        for (char c : s){
            if (c == '1'){
                ++bcount;
            } else {
                res += bcount;
            }
        }
        return res;
    }
};
