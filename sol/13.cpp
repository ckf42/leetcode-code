struct Solution {
    int romanToInt(const string &s) {
        int totalVal = 0, lastVal = 1001, val;
        for (char c: s){
            switch (c){
                case 'I':
                    val = 1;
                    break;
                case 'V':
                    val = 5;
                    break;
                case 'X':
                    val = 10;
                    break;
                case 'L':
                    val = 50;
                    break;
                case 'C':
                    val = 100;
                    break;
                case 'D':
                    val = 500;
                    break;
                case 'M':
                    val = 1000;
                    break;
            }
            if (val > lastVal){
                totalVal -= lastVal << 1;
            }
            totalVal += val;
            lastVal = val;
        }
        return totalVal;
    }
};
