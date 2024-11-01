struct Solution {
    string makeFancyString(string &s) {
        string res;
        char letter = ' ';
        int streak = 0;
        for (char c : s){
            if (c == letter && streak == 2){
                continue;
            } else if (c == letter){
                ++streak;
            } else {
                letter = c;
                streak = 1;
            }
            res += c;
        }
        return res;
    }
};
