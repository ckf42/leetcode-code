struct Solution {
    int arraySign(const vector<int>& nums) {
        bool isPos = true;
        for (const int n: nums){
            if (n == 0){
                return 0;
            } else if (n < 0){
                isPos = !isPos;
            }
        }
        return isPos ? 1 : -1;
    }
};
