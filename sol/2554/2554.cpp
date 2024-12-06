struct Solution {
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int res = 0, currSum = 0;
        vector<bool> banSet(1e4 + 1, false);
        for (int x : banned){
            banSet[x] = true;
        }
        for (int i = 1; i <= n; ++i){
            if (banSet[i]){
                continue;
            }
            if (currSum + i > maxSum){
                break;
            }
            currSum += i;
            ++res;
        }
        return res;
    }
};
