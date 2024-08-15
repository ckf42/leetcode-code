struct Solution {
    bool lemonadeChange(const vector<int>& bills) {
        int count[2] = {0, 0};
        for (const int &n : bills){
            if (n == 5){
                ++count[0];
            } else if (n == 10){
                if (count[0] == 0){
                    return false;
                } else {
                    --count[0];
                    ++count[1];
                }
            } else {
                if (count[1] >= 1 && count[0] >= 1){
                    --count[0];
                    --count[1];
                } else if (count[0] >= 3){
                    count[0] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
