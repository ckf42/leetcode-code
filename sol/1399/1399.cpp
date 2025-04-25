struct Solution {
    int countLargestGroup(int n) {
        int freq[37] = {0};
        for (int i = 1; i <= n; ++i){
            int x = i, total = 0;
            while (x != 0){
                total += x % 10;
                x /= 10;
            }
            ++freq[total];
        }
        int count = 0, maxVal = 0;
        for (int i = 1; i <= 36; ++i){
            if (freq[i] == maxVal){
                ++count;
            } else if (freq[i] > maxVal){
                maxVal = freq[i];
                count = 1;
            }
        }
        return count;
    }
};
