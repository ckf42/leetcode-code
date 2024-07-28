#include <string>

struct Solution {
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i){
            bool isSelfDiv = true;
            if (i >= 10){
                string strRep = to_string(i);
                for (const char c: strRep){
                    if (c == '0' || i % (c - '0') != 0){
                        isSelfDiv = false;
                        break;
                    }
                }
            }
            if (isSelfDiv){
                res.push_back(i);
            }
        }
        return res;
    }
};
