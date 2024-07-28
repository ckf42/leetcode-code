struct Solution {
    inline int maxChunksToSorted(vector<int>& arr) {
        int res = 0, maxVal = 0;
        for (int i = 0; i < arr.size(); ++i){
            maxVal = max(maxVal, arr[i]);
            if (i == maxVal){
                ++res;
            }
        }
        return res;
    }
};
