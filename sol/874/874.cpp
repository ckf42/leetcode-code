#include <unordered_set>

struct Solution {
    static constexpr long delta = 3e4, offset = 6e4 + 1;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, diffx = 0, diffy = 1, maxdist = 0;
        unordered_set<long> obs;
        for (auto &pt : obstacles){
            obs.insert((pt[0] + delta) * offset + pt[1] + delta);
        }
        int tempx, tempy;
        for (int cmd : commands){
            switch (cmd){
                case -2:
                    tempx = diffx;
                    tempy = diffy;
                    diffx = -tempy;
                    diffy = tempx;
                    break;
                case -1:
                    tempx = diffx;
                    tempy = diffy;
                    diffx = tempy;
                    diffy = -tempx;
                    break;
                default:
                    for (int i = 0; i < cmd; ++i){
                        tempx = x + diffx;
                        tempy = y + diffy;
                        if (obs.contains((tempx + delta) * offset + tempy + delta)){
                            break;
                        }
                        x = tempx;
                        y = tempy;
                    }
                    maxdist = max(maxdist, x * x + y * y);
            }
        }
        return maxdist;
    }
};
