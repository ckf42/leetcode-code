struct Solution {
    double new21Game(int n, int k, int maxPts) {
        if (k - 1 + maxPts <= n || k == 0){
            return 1;
        }
        vector<double> prob(k + maxPts, 0);
        for (int i = k; i <= n; ++i){
            prob[i] = 1;
        }
        prob[k - 1] = (n + 1 - k) / static_cast<double>(maxPts);
        for (int i = k - 2; i >= 0; --i){
            prob[i] = prob[i + 1] + (prob[i + 1] - prob[i + maxPts + 1]) / maxPts;
        }
        return prob[0];
    }
};
