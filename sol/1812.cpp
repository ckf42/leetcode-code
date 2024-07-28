struct Solution {
    bool squareIsWhite(const string &coordinates) {
        return (coordinates[0] + coordinates[1]) & 1;
    }
};
