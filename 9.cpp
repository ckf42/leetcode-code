struct Solution {
    constexpr bool isPalindrome(int x) {
        if (x == 0){
            return true;
        }
        if (x < 0 || x % 10 == 0){
            return false;
        }
        long xx = x, y = 0;
        while (xx > 0){
            y = y * 10 + (xx % 10);
            xx /= 10;
        }
        return x == y;
    }
};
