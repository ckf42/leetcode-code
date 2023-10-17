#include <algorithm>

struct Solution {
    string addBinary(const string &a, const string &b) {
        size_t na = a.size(), nb = b.size(), ptr = 0;
        string res;
        bool carry = false, x, y;
        while (ptr < na && ptr < nb){
            x = a[na - 1 - ptr] == '1';
            y = b[nb - 1 - ptr] == '1';
            res += (x ^ y ^ carry ? "1" : "0");
            carry = (carry & (x | y)) | (x & y);
            ++ptr;
        }
        if (ptr == nb){
            while (ptr < na){
                x = a[na - 1 - ptr] == '1';
                res += (x ^ carry ? "1" : "0");
                carry &= x;
                ++ptr;
            }
        } else {
            while (ptr < nb){
                x = b[nb - 1 - ptr] == '1';
                res += (x ^ carry ? "1" : "0");
                carry &= x;
                ++ptr;
            }
        }
        if (carry){
            res += "1";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
