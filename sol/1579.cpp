struct Solution {
    int getParent(int x, vector<int> &pArr){
        while (pArr[x] != x){
            int y = x;
            x = pArr[y];
            pArr[y] = pArr[pArr[y]];
        }
        return x;
    }
    inline bool sameGroup(int x, int y, vector<int> &pArr){
        return getParent(x, pArr) == getParent(y, pArr);
    }
    inline void unionComp(int x, int y, vector<int> &pArr, vector<int> &sArr){
        x = getParent(x, pArr);
        y = getParent(y, pArr);
        if (x == y){
            return;
        }
        if (sArr[x] < sArr[y]){
            swap(x, y);
        }
        pArr[y] = x;
        sArr[x] += sArr[y];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> edgeGp[4];
        for (int i = 0; i < edges.size(); ++i){
            edgeGp[edges[i][0]].push_back(i);
        }
        vector<int> aPar(n + 1), bPar(n + 1), aSize(n + 1, 1), bSize(n + 1, 1);
        iota(aPar.begin(), aPar.end(), 0);
        iota(bPar.begin(), bPar.end(), 0);
        int count = 0, x, y;
        for (int &i : edgeGp[3]){
            x = edges[i][1];
            y = edges[i][2];
            if (sameGroup(x, y, aPar) && sameGroup(x, y, bPar)){
                continue;
            }
            ++count;
            unionComp(x, y, aPar, aSize);
            unionComp(x, y, bPar, bSize);
        }
        if (aSize[getParent(1, aPar)] != n){
            for (int &i : edgeGp[1]){
                x = edges[i][1];
                y = edges[i][2];
                if (sameGroup(x, y, aPar)){
                    continue;
                }
                ++count;
                unionComp(x, y, aPar, aSize);
            }
        }
        if (aSize[getParent(1, aPar)] != n){
            return -1;
        }
        if (bSize[getParent(1, bPar)] != n){
            for (int &i : edgeGp[2]){
                x = edges[i][1];
                y = edges[i][2];
                if (sameGroup(x, y, bPar)){
                    continue;
                }
                ++count;
                unionComp(x, y, bPar, bSize);
            }
        }
        if (bSize[getParent(1, bPar)] != n){
            return -1;
        } else {
            return edges.size() - count;
        }
    }
};
