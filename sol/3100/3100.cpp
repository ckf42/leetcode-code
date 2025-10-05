struct Solution {
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        while (numBottles >= numExchange){
            numBottles -= numExchange++ - 1;
            ++res;
        }
        return res;
    }
};
