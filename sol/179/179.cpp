#include <algorithm>

struct Solution {
    string largestNumber(vector<int>& nums) {
        vector<string> strnum(nums.size());
        transform(nums.begin(), nums.end(), strnum.begin(), [](int x){return to_string(x);});
        ranges::sort(strnum, [](const string &a, const string &b){
            return a + b > b + a;
        });
        if (strnum[0][0] == '0'){
            return "0";
        }
        string res;
        for (string &s : strnum){
            res += s;
        }
        return res;
    }
};
