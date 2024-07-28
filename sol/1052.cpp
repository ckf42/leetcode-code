struct Solution {
    inline int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), satisfied = 0, maxGain = 0, currGain = 0;
        if (n == minutes){
            return reduce(customers.begin(), customers.end());
        }
        for (int i = 0; i < minutes; ++i){
            if (grumpy[i] == 1){
                currGain += customers[i];
            } else {
                satisfied += customers[i];
            }
        }
        maxGain = currGain;
        for (int i = minutes; i < n; ++i){
            if (grumpy[i] == 1){
                currGain += customers[i];
            } else {
                satisfied += customers[i];
            }
            if (grumpy[i - minutes] == 1){
                currGain -= customers[i - minutes];
            }
            maxGain = max(maxGain, currGain);
        }
        return satisfied + maxGain;
    }
};
