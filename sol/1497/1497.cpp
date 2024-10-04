struct Solution {
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem(k, 0);
        for (int x : arr){
            ++rem[((x % k) + k) % k];
        }
        for (int x = 0; x < k; ++x){
            if (x == 0 || x * 2 == k){
                if (rem[x] & 1){
                    return false;
                }
            } else if (rem[x] != rem[k - x]){
                return false;
            }
        }
        return true;
    }
};
