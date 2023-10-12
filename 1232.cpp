struct Solution {
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2){
            return true;
        }
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        for (size_t i = 2; i < coordinates.size(); ++i){
            if ((coordinates[i][0] - coordinates[0][0]) * dy != (coordinates[i][1] - coordinates[0][1]) * dx){
                return false;
            }
        }
        return true;
    }
};
