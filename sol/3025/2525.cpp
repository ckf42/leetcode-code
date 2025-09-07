struct Solution {
    int numberOfPairs(vector<vector<int>>& points) {
        ranges::sort(points, [](auto &a, auto &b){
            return a[1] * 100 - a[0] < b[1] * 100 - b[0];
        });
        int n = points.size(), res = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (points[i][0] < points[j][0]){
                    continue;
                }
                bool isValid = true;
                for (int k = i + 1; k < j; ++k){
                    if (points[i][0] >= points[k][0] && points[k][0] >= points[j][0]){
                        isValid = false;
                        break;
                    }
                }
                res += isValid;
            }
        }
        return res;
    }
};
