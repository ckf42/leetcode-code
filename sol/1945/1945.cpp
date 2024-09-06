struct Solution {
    int getLucky(string &s, int k) {
        int res = 0;
        for (char c : s){
            int cn = c - 96;
            res += cn / 10 + cn % 10;
        }
        while (--k > 0){
            int tmp = 0;
            while (res != 0){
                tmp += res % 10;
                res /= 10;
            }
            res = tmp;
        }
        return res;
    }
};
