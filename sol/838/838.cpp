struct Solution {
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> fronts, fallDir(n, 0), proposedFall;
        for (int i = 0; i < n; ++i){
            if (dominoes[i] != '.'){
                fronts.push_back(i);
            }
        }
        while (!fronts.empty()){
            proposedFall.clear();
            for (int i : fronts){
                int d = dominoes[i] == 'R' ? 1 : -1;
                int nextToFall = i + d;
                if (nextToFall < 0 || nextToFall >= n || dominoes[nextToFall] != '.'){
                    continue;
                }
                fallDir[nextToFall] += d;
                proposedFall.push_back(nextToFall);
            }
            fronts.clear();
            for (int idx : proposedFall){
                if (fallDir[idx] == 0){
                    continue;
                }
                dominoes[idx] = fallDir[idx] == 1 ? 'R' : 'L';
                fronts.push_back(idx);
                fallDir[idx] = 0;
            }
        }
        return dominoes;
    }
};
