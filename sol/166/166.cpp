#include <unordered_map>

struct Solution {
    using ll = long long;
    string fractionToDecimal(int numerator, int denominator) {
        ll n = numerator, d = denominator;
        if (n == 0){
            return "0";
        }
        if (d < 0){
            n = -n;
            d = -d;
        }
        string res;
        if (n < 0){
            res.push_back('-');
            n = -n;
        }
        ll q = n / d, r = n % d;
        res += to_string(q);
        if (r == 0){
            return res;
        }
        res.push_back('.');
        int idx = 0;
        vector<char> buff;
        unordered_map<ll, int> seenRem;
        seenRem[r] = 0;
        while (true){
            r *= 10;
            q = r / d;
            r %= d;
            buff.push_back('0' + q);
            ++idx;
            if (r == 0 || seenRem.contains(r)){
                break;
            }
            seenRem[r] = idx;
        }
        if (r == 0){
            res.reserve(res.size() + buff.size());
            res.insert(res.end(), buff.begin(), buff.end());
        } else {
            res.reserve(res.size() + buff.size() + 2);
            int lim = seenRem[r];
            res.insert(res.end(), buff.begin(), buff.begin() + lim);
            res.push_back('(');
            res.insert(res.end(), buff.begin() + lim, buff.end());
            res.push_back(')');
        }
        return res;
    }
};
