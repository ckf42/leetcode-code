struct Solution {
    void setZeroes(vector<vector<int>>& matrix) {
        short m = matrix.size(), n = matrix.front().size();
        short markerRow = -1, markerCol = -1, i, j;
        for (i = 0; i < m; ++i){
            for (j = 0; j < n; ++j){
                if (matrix[i][j] == 0){
                    markerRow = i;
                    markerCol = j;
                    break;
                }
            }
            if (markerRow != -1){
                break;
            }
        }
        if (markerRow == -1){
            return;
        }
        for (i = 0; i < m; ++i){
            if (i == markerRow){
                continue;
            }
            matrix[i][markerCol] = (matrix[i][markerCol] != 0 ? 0 : 1);
        }
        for (j = 0; j < n; ++j){
            if (j == markerCol){
                continue;
            }
            matrix[markerRow][j] = (matrix[markerRow][j] != 0 ? 0 : 1);
        }
        for (i = markerRow + 1; i < m; ++i){
            for (j = 0; j < n; ++j){
                if (j == markerCol){
                    continue;
                }
                if (matrix[i][j] == 0){
                    matrix[markerRow][j] = 1;
                    matrix[i][markerCol] = 1;
                }
            }
        }
        for (i = 0; i < m; ++i){
            if (matrix[i][markerCol] == 1){
                for (j = 0; j < n; ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        for (j = 0; j < n; ++j){
            if (matrix[markerRow][j] == 1){
                for (i = 0; i < m; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
