struct Solution {
    string removeKdigits(string &num, int k) {
        int zeroCount = 0;
        for (char &c : num){
            zeroCount += c == '0';
        }
        if (zeroCount + k >= num.size()){
            return "0";
        }
        string res;
        for (char &c : num){
            while (k > 0 && res.size() > 0 && c < res.back()){
                res.pop_back();
                --k;
            }
            if (res.size() > 0 || c != '0'){
                res.push_back(c);
            }
        }
        while (res.size() > 0 && k-- > 0){
            res.pop_back();
        }
        if (res.size() == 0){
            return "0";
        } else {
            return res;
        }
    }
};
