struct Solution {
    bool winnerOfGame(const string &colors) {
        size_t asum = 0, bsum = 0, lastIdx = 0, n = colors.size();
        char lastChar = colors[0];
        for (size_t i = 1; i < colors.size(); ++i){
            if (colors[i] != lastChar){
                if (i >= 3 + lastIdx){
                    if (lastChar == 'A'){
                        asum += i - lastIdx - 2;
                    } else {
                        bsum += i - lastIdx - 2;
                    }
                }
                lastChar = colors[i];
                lastIdx = i;
            }
        }
        if (n >= 3 + lastIdx){
            if (lastChar == 'A'){
                asum += n - lastIdx - 2;
            } else {
                bsum += n - lastIdx - 2;
            }
        }
        return asum > bsum;
    }
};
