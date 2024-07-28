struct Solution {
    inline bool threeConsecutiveOdds(vector<int>& arr) {
        short oddCount = 0;
        for (int &x : arr){
            if (x & 1){
                if (++oddCount == 3){
                    return true;
                }
            } else {
                oddCount = 0;
            }
        }
        return false;
    }
};
