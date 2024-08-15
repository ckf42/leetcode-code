struct Solution {
    inline bool canMakeSquare(vector<vector<char>>& grid) {
        return (grid[0][0] + grid[0][1] + grid[1][0] + grid[1][1] != 306)
                || (grid[0][1] + grid[0][2] + grid[1][1] + grid[1][2] != 306)
                || (grid[1][0] + grid[1][1] + grid[2][0] + grid[2][1] != 306)
                || (grid[1][1] + grid[1][2] + grid[2][1] + grid[2][2] != 306);
    }
};
