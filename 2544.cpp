struct Solution {
    int alternateDigitSum(int n) {
        int s = 0, r;
        bool flag = false;
        while (n != 0){
            r = n % 10;
            n /= 10;
            s += (flag ? r : -r);
            flag = !flag;
        }
        return (flag ? -s : s);
    }
};
