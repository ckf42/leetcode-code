struct Solution {
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diag = 0, area = 0;
        for (auto &r : dimensions){
            int d = r[0] * r[0] + r[1] * r[1];
            if (d > diag){
                diag = d;
                area = r[0] * r[1];
            } else if (d == diag){
                area = max(area, r[0] * r[1]);
            }
        }
        return area;
    }
};
