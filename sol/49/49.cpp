#include <unordered_map>

struct Solution {
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        string sortedS;
        unordered_map<string, vector<int>> gps;
        for (int i = 0; i < strs.size(); ++i){
            sortedS = strs[i];
            sort(sortedS.begin(), sortedS.end());
            gps[sortedS].push_back(i);
        }
        for (const pair<const string, vector<int>> &pr : gps){
            vector<string> buffer;
            for (int idx : pr.second){
                buffer.push_back(strs[idx]);
            }
            res.push_back(buffer);
        }
        return res;
    }
};
