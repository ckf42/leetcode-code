struct Solution {
    int rotatedDigits(int n) {
        int count = 0;
        vector<char> memo(n + 1, 0);
        for (int i = 0; i <= n; ++i){
            if (i < 10){
                switch (i){
                    case 0:
                    case 1:
                    case 8:
                        memo[i] = 1;
                        break;
                    case 2:
                    case 5:
                    case 6:
                    case 9:
                        memo[i] = 2;
                        ++count;
                        break;
                }
            } else {
                int a = memo[i / 10], b = memo[i % 10];
                if (a == 1 && b == 1){
                    memo[i] = 1;
                } else if (a != 0 && b != 0) {
                    memo[i] = 2;
                    ++count;
                }
            }
        }
        return count;
    }
};
