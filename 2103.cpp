struct Solution {
    int countPoints(string &rings) {
        int m = 0, k = 0;
        for (int i = 0; i < rings.size(); ++++i){
            k = 0;
            switch (rings[i]){
                case 'R':
                    ++k;
                case 'G':
                    ++k;
                case 'B':
                    break;
            }
            k += (rings[i + 1] - '0') * 3;
            m |= (1 << k);
        }
        int c = 0;
        while (m != 0){
            if ((m & 7) == 7){
                ++c;
            }
            m >>= 3;
        }
        return c;
    }
};
