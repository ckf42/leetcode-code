struct Solution {
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxval = energy[n - k];
        for (int i = n - k + 1; i < n; ++i){
            maxval = max(maxval, energy[i]);
        }
        for (int i = n - k - 1; i >= 0; --i){
            energy[i] += energy[i + k];
            maxval = max(maxval, energy[i]);
        }
        return maxval;
    }
};
