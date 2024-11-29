#include <deque>
#include <unordered_set>

struct Solution {
    using Config = array<int, 6>;
    static constexpr Config GOALCONFIG = {1, 2, 3, 4, 5, 0};
    static constexpr int SWAPLOC[6][3] = {
            {1, 3, -1},
            {0, 2, 4},
            {1, 5, -1},
            {4, 0, -1},
            {3, 5, 1},
            {4, 2, -1}
        };

    static int getPermIdx(const Config &config) {
        int res = 0, accum = 1;
        for (int i = 4; i >= 0; --i){
            int count = 0;
            for (int j = i + 1; j < 6; ++j){
                if (config[j] < config[i]){
                    ++count;
                }
            }
            res += count * accum;
            accum *= 6 - i;
        }
        return res;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        Config initConfig;
        for (int i = 0; i < 3; ++i){
            initConfig[i] = board[0][i];
            initConfig[i + 3] = board[1][i];
        }
        deque<pair<int, Config>> q;
        q.push_back({0, initConfig});
        unordered_set<int> visited;
        while (!q.empty()){
            int mvs = q.front().first;
            Config config = q.front().second;
            q.pop_front();
            if (config == this->GOALCONFIG){
                return mvs;
            }
            int permIdx = this->getPermIdx(config);
            if (visited.contains(permIdx)){
                continue;
            }
            visited.insert(permIdx);
            ++mvs;
            int idx = 0;
            for (int i = 0; i < 6; ++i){
                if (config[i] == 0){
                    idx = i;
                    break;
                }
            }
            for (int i = 0; i < 3; ++i){
                if (this->SWAPLOC[idx][i] == -1){
                    break;
                }
                swap(config[idx], config[this->SWAPLOC[idx][i]]);
                q.push_back({mvs, config});
                swap(config[idx], config[this->SWAPLOC[idx][i]]);
            }
        }
        return -1;
    }
};
