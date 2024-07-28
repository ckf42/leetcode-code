struct Solution {
    int kthFactor(int n, int k) {
        vector<int> small, large;
        for (int i = 1; i * i <= n; ++i){
            if (n % i == 0){
                small.push_back(i);
                int q = n / i;
                if (q != i){
                    large.push_back(q);
                }
                if (small.size() == k){
                    return i;
                }
            }
        }
        if (small.size() + large.size() >= k){
            return large[large.size() + small.size() - k];
        } else {
            return -1;
        }
    }
};
