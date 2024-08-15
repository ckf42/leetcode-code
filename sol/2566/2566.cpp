#include <algorithm>

struct Solution {
    int minMaxDifference(int num) const {
        string s = to_string(num);
        char target = 0;
        for (char c : s){
            if (c != '9'){
                target = c;
                break;
            }
        }
        if (target == 0){
            return num;
        }
        string ss = s;
        replace(ss.begin(), ss.end(), s[0], '0');
        replace(s.begin(), s.end(), target, '9');
        return stoi(s) - stoi(ss);
    }
};
