struct Solution {
    int maxWidthOfVerticalArea(const vector<vector<int>>& points) {
        vector<int> xCoor(points.size(), 0);
        for (int i = 0; i < points.size(); ++i){
            xCoor[i] = points[i][0];
        }
        sort(xCoor.begin(), xCoor.end());
        int diff = xCoor[1] - xCoor[0];
        for (int i = 2; i < points.size(); ++i){
            diff = max(diff, xCoor[i] - xCoor[i - 1]);
        }
        return diff;
    }
};
