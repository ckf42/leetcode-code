struct Solution {
    int numSub(string_view s) {
        constexpr int m = 1e9 + 7;
        int res = 0, count = 0;
        for (char c : s){
            if (c == '1'){
                res = (res + ++count) % m;
            } else {
                count = 0;
            }
        }
        return res;
    }
};
