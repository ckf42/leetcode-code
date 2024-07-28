struct Solution {
    string truncateSentence(string &s, int k) {
        int pos = -1;
        while (k-- > 0){
            pos = s.find(' ', pos + 1);
        }
        return s.substr(0, pos);
    }
};
