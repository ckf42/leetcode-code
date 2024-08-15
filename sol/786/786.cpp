struct Solution {
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size(), nidx = 0, didx = 1, prelen = -1, j, val;
        while (prelen != k - 1){
            prelen = 0;
            j = 1;
            for (int i = 0; i < n - 1; ++i){
                val = arr[i] * arr[didx];
                while (j < n && val >= arr[j] * arr[nidx]){
                    ++j;
                }
                prelen += n - j;
            }
            if (prelen > k - 1){
                ++didx;
            } else if (prelen < k - 1){
                ++nidx;
            }
        }
        return {arr[nidx], arr[didx]};
    }
};
