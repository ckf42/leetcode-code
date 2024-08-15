struct Solution {
    int findSpecialInteger(const vector<int>& arr) {
        int lastEle = -1, combo = 0;
        for (const int &n : arr){
            if (n == lastEle){
                ++combo;
            } else {
                combo = 1;
            }
            lastEle = n;
            if (combo * 4 > arr.size()){
                break;
            }
        }
        return lastEle;
    }
};
