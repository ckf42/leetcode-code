#include <unordered_map>
#include <unordered_set>

struct Solution {
    using pr = pair<int, int>;

    struct pairHash {
        size_t operator()(const pr &p) const {
            return std::hash<uint32_t>()(p.first) ^ std::hash<uint32_t>()(p.second);
        }
    };
    
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> hori, vert, diag1, diag2;
        unordered_set<pr, pairHash> lampMap;
        for (auto &coor : lamps){
            int i = coor[0], j = coor[1];
            if (!lampMap.contains({i, j})){
                ++hori[i];
                ++vert[j];
                ++diag1[i - j];
                ++diag2[i + j];
                lampMap.emplace(i, j);
            }
        }
        vector<int> res;
        for (auto &coor : queries){
            int i = coor[0], j = coor[1];
            if (hori[i] != 0 || vert[j] != 0 || diag1[i - j] != 0 || diag2[i + j] != 0){
                res.push_back(1);
            } else {
                res.push_back(0);
            }
            for (int ii = max(0, i - 1); ii < min(n, i + 2); ++ii){
                for (int jj = max(0, j - 1); jj < min(n, j + 2); ++jj){
                    if (lampMap.contains({ii, jj})){
                        lampMap.erase({ii, jj});
                        --hori[ii];
                        --vert[jj];
                        --diag1[ii - jj];
                        --diag2[ii + jj];
                    }
                }
            }
        }
        return res;
    }
};
