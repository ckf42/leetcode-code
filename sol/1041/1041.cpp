struct Solution {
    static constexpr int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isRobotBounded(const string &instructions) {
        int x = 0, y = 0, idx = 1;
        for (const char &c : instructions){
            switch (c){
                case 'L':
                    idx = (idx + 1) & 3;
                    break;
                case 'R':
                    idx = (idx + 3) & 3;
                    break;
                default:
                    x += this->directions[idx][0];
                    y += this->directions[idx][1];
            }
        }
        return (x == 0 && y == 0) || idx != 1;
    }
};
