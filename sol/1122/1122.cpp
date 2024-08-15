struct Solution {
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;
        for (int &x : arr2){
            freq[x] = 0;
        }
        int len = 0;
        for (int i = arr1.size() - 1; i >= 0; --i){
            if (freq.contains(arr1[i])){
                ++freq[arr1[i]];
            } else {
                arr1[arr1.size() - (++len)] = arr1[i];
            }
        }
        sort(arr1.end() - len, arr1.end());
        len = 0;
        for (int &x : arr2){
            for (int i = 0; i < freq[x]; ++i){
                arr1[len++] = x;
            }
        }
        return arr1;
    }
};
