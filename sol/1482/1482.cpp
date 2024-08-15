struct Solution {
    inline int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n / k < m){
            return -1;
        }
        auto [lp, rp] = minmax_element(bloomDay.begin(), bloomDay.end());
        int l = *lp, r = *rp + 1, p, bonq, seg;
        while (l < r){
            p = (l + r) / 2;
            bonq = 0;
            seg = 0;
            for (int &x : bloomDay){
                if (x <= p){
                    ++seg;
                } else {
                    bonq += seg / k;
                    seg = 0;
                }
                if (bonq >= m){
                    break;
                }
            }
            bonq += seg / k;
            if (bonq < m){
                l = p + 1;
            } else {
                r = p;
            }
        }
        return l;
    }
};
