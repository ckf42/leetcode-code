#include <map>

struct Solution {
    vector<vector<int>> mergeSimilarItems(const vector<vector<int>>& items1, const vector<vector<int>>& items2) {
        map<int, int> m;
        for (const vector<int> &item : items1){
            m[item[0]] = item[1];
        }
        for (const vector<int> &item : items2){
            if (m.contains(item[0])){
                m[item[0]] += item[1];
            } else {
                m[item[0]] = item[1];
            }
        }
        vector<vector<int>> res;
        for (const auto &p : m){
            res.push_back({p.first, p.second});
        }
        return res;
    }
};
