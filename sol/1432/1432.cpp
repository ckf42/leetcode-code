struct Solution {
    int maxDiff(int num) {
        int lmask = 1;
        while (lmask <= num){
            lmask *= 10;
        }
        lmask /= 10;
        int a = num, mask = lmask, targetd = -1, d;
        while (mask != 0){
            d = (a / mask) % 10;
            if (targetd == -1 && d != 9){
                targetd = d;
            }
            if (d == targetd){
                a += (9 - targetd) * mask;
            }
            mask /= 10;
        }
        int b = num;
        targetd = -1;
        mask = lmask;
        if (num < 10){
            b = 1;
        } else if ((d = (num / lmask) % 10) != 1){
            targetd = d;
            while (mask != 0){
                if ((d = (b / mask) % 10) == targetd){
                    b -= (targetd - 1) * mask;
                }
                mask /= 10;
            }
        } else {
            mask /= 10;
            while (mask != 0){
                d = (b / mask) % 10;
                if (targetd == -1 && d != 0 && d != 1){
                    targetd = d;
                }
                if (d == targetd){
                    b -= targetd * mask;
                }
                mask /= 10;
            }
        }
        return a - b;
    }
};
