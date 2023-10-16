struct Solution {
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix.front().size(), x = 0, y = 0, newx = 0, newy = 0;
        int d = 3;
        constexpr int dirDict[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        while (true){
            x = newx, y = newy;
            res.push_back(matrix[x][y]);
            matrix[x][y] = -101;
            newx = x + dirDict[d][0];
            newy = y + dirDict[d][1];
            if (!(0 <= newx && newx < m && 0 <= newy && newy < n && matrix[newx][newy] != -101)){
                d = (d + 1) & 3;
            }
            newx = x + dirDict[d][0];
            newy = y + dirDict[d][1];
            if (!(0 <= newx && newx < m && 0 <= newy && newy < n && matrix[newx][newy] != -101)){
                break;
            }
        }
        return res;
    }
};
