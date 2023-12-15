#include <unordered_set>

struct Solution {
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (auto &p : paths){
            s.insert(p[0]);
        }
        for (auto &p : paths){
            if (!s.contains(p[1])){
                return p[1];
            }
        }
        return "";
    }
};
