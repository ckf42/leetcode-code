struct Solution {
    bool judgeCircle(const string &moves) {
        int x = 0, y = 0;
        for (const char &c : moves){
            switch (c){
                case 'U':
                    ++y;
                    break;
                case 'D':
                    --y;
                    break;
                case 'L':
                    --x;
                    break;
                case 'R':
                    ++x;
                    break;
            }
        }
        return x == 0 && y == 0;
    }
};
