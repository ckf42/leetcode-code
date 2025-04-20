#include <unordered_map>

struct Solution {
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for (int x : answers){
            ++c[x + 1];
        }
        int res = 0;
        for (auto [k, q] : c){
            res += ((q + k - 1) / k) * k;
        }
        return res;
    }
};
