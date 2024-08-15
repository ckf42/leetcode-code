struct Solution {
    static constexpr char 
        *ones[10] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"},
        *tens[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"},
        *teens[9] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    inline string basicPart(int n){
        vector<string> res;
        if (n >= 100){
            res.push_back(this->ones[n / 100 - 1]);
            res.push_back("Hundred");
            n %= 100;
        }
        if (n >= 20){
            res.push_back(this->tens[n / 10 - 2]);
            n %= 10;
        } else if (n >= 11){
            res.push_back(this->teens[n - 11]);
            n = 0;
        }
        if (n > 0){
            res.push_back(this->ones[n - 1]);
        }
        string resStr = res[0];
        for (int i = 1; i < res.size(); ++i){
            resStr += " " + res[i];
        }
        return resStr;
    }
    string numberToWords(int n) {
        if (n == 0){
            return "Zero";
        }
        vector<string> res;
        int q = n % 1000;
        n /= 1000;
        if (q != 0){
            res.push_back(this->basicPart(q));
        }
        if (n > 0){
            q = n % 1000;
            n /= 1000;
            if (q != 0){
                res.push_back("Thousand");
                res.push_back(this->basicPart(q));
            }
        }
        if (n > 0){
            q = n % 1000;
            n /= 1000;
            if (q != 0){
                res.push_back("Million");
                res.push_back(this->basicPart(q));
            }
        }
        if (n > 0){
            q = n % 1000;
            n /= 1000;
            if (q != 0){
                res.push_back("Billion");
                res.push_back(this->basicPart(q));
            }
        }
        string resStr = res.back();
        for (int i = res.size() - 2; i >= 0; --i){
            resStr += " " + res[i];
        }
        return resStr;
    }
};
