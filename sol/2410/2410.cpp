struct Solution {
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        ranges::sort(players);
        ranges::sort(trainers);
        int n = trainers.size(), ptr = 0, res = 0;
        for (int p : players){
            while (ptr != n && trainers[ptr] < p){
                ++ptr;
            }
            if (ptr == n){
                break;
            }
            ++res;
            ++ptr;
        }
        return res;
    }
};
