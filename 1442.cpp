struct Solution {
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), count = 0;
        vector<int> prefix(n + 1);
        prefix[1] = arr[0];
        for (int k = 1; k < n; ++k){
            prefix[k + 1] = prefix[k] ^ arr[k];
            for (int i = 0; i < k; ++i){
                if (prefix[k + 1] == prefix[i]){
                    count += k - i;
                }
            }
        }
        return count;
    }
};
