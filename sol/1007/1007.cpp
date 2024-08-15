struct Solution {
    inline int count(int x, vector<int>& tops, vector<int>& bottoms){
        int c = 0, d = 0, t, b;
        for (int i = 0; i < tops.size(); ++i){
            t = tops[i];
            b = bottoms[i];
            if (t != x && b != x){
                return -1;
            }
            if (t != x && b == x){
                ++c;
            } else if (b != x && t == x){
                ++d;
            }
        }
        return min(c, d);
    }
    inline int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = this->count(tops[0], tops, bottoms);
        if (tops[0] != bottoms[0]){
            int val = this->count(bottoms[0], tops, bottoms);
            if (res == -1 || (res > val && val != -1)){
                res = val;
            }
        }
        return res;
    }
};
