struct Solution {
    int minMaxDifference(int num) const {
        int minNum = num, target = 0, d;
        while (minNum != 0){
            d = minNum % 10;
            if (d != 9){
                target = d;
            }
            minNum /= 10;
        }
        minNum = num;
        int topDigit = d, mask = 1;
        while (mask <= num){
            d = (num / mask) % 10;
            if (d == topDigit){
                minNum -= topDigit * mask;
            }
            if (d == target){
                num += (9 - target) * mask;
            }
            mask *= 10;
        }
        return num - minNum;
    }
};
