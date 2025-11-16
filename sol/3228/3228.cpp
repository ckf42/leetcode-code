struct Solution {
    int maxOperations(string_view s) {
        int res = 0, count = 0, total = 0;
        char prev = ' ';
        for (char c : s){
            if (c != prev){
                if (prev == '1'){
                    total += count;
                    res += total;
                }
                count = 0;
                prev = c;
            }
            if (c == '1'){
                ++count;
            }
        }
        return res;
    }
};
