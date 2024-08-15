#include <map>

struct Solution {
    int deleteAndEarn(const vector<int>& nums) {
        map<int, int> counter;
        for (const int &n: nums){
            if (counter.contains(n)){
                ++counter[n];
            } else {
                counter[n] = 1;
            }
        }
        map<int, int>::const_iterator it = counter.cbegin();
        int prev = it->first * it->second, prevk = it->first;
        if (counter.size() == 1){
            return prev;
        }
        ++it;
        int val = it->first * it->second, temp;
        if (it->first == prevk + 1){
            val = max(val, prev);
        } else {
            val += prev;
        }
        prevk = it->first;
        ++it;
        while (it != counter.cend()){
            temp = it->first * it->second;
            if (it->first == prevk + 1){
                temp = max(temp + prev, val);
            } else {
                temp += val;
            }
            prev = val;
            val = temp;
            prevk = it->first;
            ++it;
        }
        return val;
    }
};
