struct Solution {
    string largestGoodInteger(const string &num) {
        string res = "";
        int combo = 0;
        char lastDigit = '0' - 1;
        for (char c : num){
            if (c == lastDigit){
                combo += 1;
            } else {
                combo = 1;
                lastDigit = c;
            }
            if (combo == 3){
                if (res == "" || lastDigit > res[0]){
                    res = string(3, lastDigit);
                }
                combo = 0;
            }
        }
        return res;
    }
};
