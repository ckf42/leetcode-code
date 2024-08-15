struct Solution {
    char findTheDifference(const string &s, const string &t) {
        short tot = 0;
        for (const char &c : t){
            tot += c;
        }
        for (const char &c : s){
            tot -= c;
        }
        return tot;
    }
};
