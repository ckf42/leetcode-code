struct Solution {
    int findInMountainArray(int target, MountainArray &mountainArr) {
        size_t n = mountainArr.length();
        int s = 0, e = n - 1, peak, m;
        while (s < e){
            m = (s + e) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1)){
                s = m + 1;
            } else {
                e = m;
            }
        }
        peak = s;
        s = 0, e = peak;
        while (s <= e){
            m = (s + e) / 2;
            const int &v = mountainArr.get(m);
            if (v == target){
                return m;
            }
            if (v < target){
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        s = peak, e = n - 1;
        while (s <= e){
            m = (s + e) / 2;
            const int &v = mountainArr.get(m);
            if (v == target){
                return m;
            }
            if (v > target){
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return -1;
    }
};
