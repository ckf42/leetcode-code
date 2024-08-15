struct Solution {
    inline string largestOddNumber(const string &num) {
        int len = num.size();
        while (len > 0 && !(num[len - 1] & 1)){
            --len;
        }
        return num.substr(0, len);
    }
};
