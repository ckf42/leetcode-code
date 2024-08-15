struct Solution {
    inline int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, buff = 0;
        while (numBottles > 0){
            res += numBottles;
            numBottles += buff;
            buff = numBottles % numExchange;
            numBottles = numBottles / numExchange;
        }
        return res;
    }
};
