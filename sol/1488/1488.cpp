#include <unordered_map>

struct Solution {
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 0), nextVacant(n, n);
        int spot = n;
        for (int i = n - 1; i >= 0; --i){
            nextVacant[i] = spot;
            if (rains[i] == 0){
                spot = i;
            } else {
                res[i] = -1;
            }
        }
        unordered_map<int, int> fillDay;
        for (int d = 0; d < n; ++d){
            int target = rains[d];
            if (target == 0){
                continue;
            }
            if (fillDay.contains(target)){
                int r = fillDay[target];
                spot = nextVacant[r];
                while (spot < d && res[spot] != 0){
                    spot = nextVacant[spot];
                }
                if (spot >= d){
                    return vector<int>();
                }
                nextVacant[nextVacant[r]] = nextVacant[spot];
                res[spot] = target;
            }
            fillDay[target] = d;
        }
        for (int &x : res){
            if (x == 0){
                x = 1;
            }
        }
        return res;
    }
};
