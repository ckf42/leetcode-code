#include <unordered_set>

struct Solution {
    int reverseNum(int n){
        int newNum = 0;
        while (n != 0){
            newNum *= 10;
            newNum += n % 10;
            n /= 10;
        }
        return newNum;
    }

    int countDistinctIntegers(const vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums){
            s.insert(n);
            s.insert(this->reverseNum(n));
        }
        return s.size();
    }
};
