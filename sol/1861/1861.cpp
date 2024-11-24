struct Solution {
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i = 0; i < m; ++i){
            int ptr = n - 1;
            for (int j = n - 1; j >= 0; --j){
                switch (box[i][j]){
                    case '#':
                        box[i][j] = '.';
                        res[ptr--][m - 1 - i] = '#';
                        break;
                    case '*':
                        res[j][m - 1 - i] = '*';
                        ptr = j - 1;
                        break;
                }
            }
        }
        return res;
    }
};
