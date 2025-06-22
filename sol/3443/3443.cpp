struct Solution {
    int maxDistance(string_view s, int k) {
        int counts[4] = {0}, res = -1;
        for (char c : s){
            switch (c){
                case 'N':
                    ++counts[0];
                    break;
                case 'S':
                    ++counts[1];
                    break;
                case 'E':
                    ++counts[2];
                    break;
                case 'W':
                    ++counts[3];
                    break;
            }
            int d = abs(counts[0] - counts[1]) + abs(counts[2] - counts[3]);
            res = max(
                res,
                d + min(
                    k, 
                    min(counts[0], counts[1]) + min(counts[2], counts[3])
                ) * 2
            );
        }
        return res;
    }
};
