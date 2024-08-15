struct Solution {
    constexpr int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int b = minutesToTest / minutesToDie + 1, mul = 1, counter = 0;
        while (mul < buckets){
            mul *= b;
            ++counter;
        }
        return counter;
    }
};
