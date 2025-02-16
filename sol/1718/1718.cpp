struct Solution {
    bool fill(int i, vector<int> &res, vector<bool> &used, int n, int m){
        if (i == m){
            return true;
        }
        if (res[i] != 0){
            return this->fill(i + 1, res, used, n, m);
        }
        for (int v = n; v > 1; --v){
            if (used[v] || (i + v >= m) || (res[i + v] != 0)){
                continue;
            }
            res[i] = v;
            res[i + v] = v;
            used[v] = true;
            if (this->fill(i + 1, res, used, n, m)){
                return true;
            }
            res[i] = 0;
            res[i + v] = 0;
            used[v] = false;
        }
        if (!used[1]){
            res[i] = 1;
            used[1] = true;
            if (this->fill(i + 1, res, used, n, m)){
                return true;
            }
            res[i] = 0;
            used[1] = false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        this->fill(0, res, used, n, 2 * n - 1);
        return res;
    }
};
