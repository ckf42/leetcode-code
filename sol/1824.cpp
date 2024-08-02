struct Solution {
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1, jumps = 0;
        char pos = 0b0100;
        for (int i = 1; i <= n; ++i){
            pos &= 0b1111 ^ (1 << obstacles[i]);
            if (pos == 0){
                ++jumps;
                pos = 0b1110 & (0b1111 ^ ((1 << obstacles[i]) | (1 << obstacles[i - 1])));
            }
        }
        return jumps;
    }
};
