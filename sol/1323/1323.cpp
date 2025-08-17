struct Solution {
    int maximum69Number (int num) {
        int x = num, mask = 1, update = 0;
        while (x > 0){
            if (x % 10 == 6){
                update = mask * 3;
            }
            mask *= 10;
            x /= 10;
        }
        return num + update;
    }
};
