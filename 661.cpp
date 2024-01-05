struct Solution {
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size(), counter, total;
        vector<vector<int>> newimg(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                counter = 0;
                total = 0;
                for (int di = -1; di <= 1; ++di){
                    for (int dj = -1; dj <= 1; ++dj){
                        int ii = i + di, jj = j + dj;
                        if (!(0 <= ii && ii < m && 0 <= jj && jj < n)){
                            continue;
                        }
                        total += img[ii][jj];
                        ++counter;
                    }
                }
                newimg[i][j] = total / counter;
            }
        }
        return newimg;
    }
};
