#include <unordered_set>

struct Solution {
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> seen, buff, temp;
        for (int x : arr){
            temp.clear();
            temp.insert(x);
            for (int y : buff){
                temp.insert(x | y);
            }
            seen.insert(temp.begin(), temp.end());
            swap(buff, temp);
        }
        return seen.size();
    }
};
