struct Solution {
    int minOperations(vector<vector<int>>& grid, int x) {
        int remainder = grid[0][0] % x;
        vector<int> valList;
        for (auto &r : grid){
            for (int v : r){
                if (v % x != remainder){
                    return -1;
                }
            }
            valList.insert(valList.end(), r.begin(), r.end());
        }
        ranges::nth_element(valList, valList.begin() + valList.size() / 2);
        int target = valList[valList.size() / 2], res = 0;
        for (int v : valList){
            res += abs(v - target) / x;
        }
        return res;
    }
};
