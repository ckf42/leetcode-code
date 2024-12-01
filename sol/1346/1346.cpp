#include <bitset>

struct Solution {
    bool checkIfExist(vector<int>& arr) {
        bitset<2001> h;
        for (int x : arr){
            if ((x >= -500 && x <= 500 && h[(x << 1) + 1000])
                || ((x & 1) == 0 && h[(x >> 1) + 1000])
            ){
                return true;
            }
            h.set(x + 1000);
        }
        return false;
    }
};
