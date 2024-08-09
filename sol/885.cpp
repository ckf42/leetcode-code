struct Solution {
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int tot = rows * cols, i = rStart, j = cStart, l = 1, ptr = 1;
        vector<vector<int>> res(tot, vector<int>(2, 0));
        res[0] = {i, j};
        while (ptr < tot){
            if (0 <= i && i < rows){
                for (int step = 1; step <= l; ++step){
                    if (0 <= j + step && j + step < cols){
                        res[ptr++] = {i, j + step};
                    }
                }
            }
            j += l;
            if (0 <= j && j < cols){
                for (int step = 1; step <= l; ++step){
                    if (0 <= i + step && i + step < rows){
                        res[ptr++] = {i + step, j};
                    }
                }
            }
            i += l;
            ++l;
            if (0 <= i && i < rows){
                for (int step = 1; step <= l; ++step){
                    if (0 <= j - step && j - step < cols){
                        res[ptr++] = {i, j - step};
                    }
                }
            }
            j -= l;
            if (0 <= j && j < cols){
                for (int step = 1; step <= l; ++step){
                    if (0 <= i - step && i - step < rows){
                        res[ptr++] = {i - step, j};
                    }
                }
            }
            i -= l;
            ++l;
        }
        return res;
    }
};
