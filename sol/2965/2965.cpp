struct Solution {
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = 0, totalSq = 0, counter = 1;
        for (auto &row : grid){
            for (int x : row){
                total += x - counter;
                totalSq += x * x - counter * counter;
                ++counter;
            }
        }
        int c = totalSq / total;
        int a = (c + total) / 2;
        return {a, c - a};
    }
};
