#include <array>

struct Solution {
    int countCharacters(const vector<string>& words, const string &chars) {
        array<int, 26> charCounter = {0};
        for (char c: chars){
            ++charCounter[c - 'a'];
        }
        int res = 0;
        for (const string &w : words){
            array<int, 26> counter = charCounter;
            bool failed = false;
            for (char c : w){
                if (counter[c - 'a'] > 0){
                    --counter[c - 'a'];
                } else {
                    failed = true;
                    break;
                }
            }
            if (!failed){
                res += w.size();
            }
        }
        return res;
    }
};
