struct Solution {
    string convertToBase7(int num) {
        if (num == 0){
            return "0";
        }
        vector<char> res;
        bool sgn = false;
        if (num < 0){
            sgn = true;
            num *= -1;
        }
        while (num != 0){
            res.push_back('0' + num % 7);
            num /= 7;
        }
        return (sgn ? "-" : "") + string(res.crbegin(), res.crend());
    }
};
