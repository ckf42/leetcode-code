struct Solution {
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n + 1, 0);
        for (int x : arr){
            if (x <= n){
                ++freq[x];
            }
        }
        for (int i = n; i > 0; --i){
            if (freq[i] == i){
                return i;
            }
        }
        return -1;
    }
};
