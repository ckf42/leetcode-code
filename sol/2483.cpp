struct Solution {
    int bestClosingTime(string &customers) {
        int n = customers.size();
        int bestTime = 0, bestPen = 0, p = 0;
        for (int i = 0; i < n; ++i){
            p += 1 - 2 * (customers[i] == 'Y');
            if (p < bestPen){
                bestPen = p;
                bestTime = i + 1;
            }
        }
        return bestTime;
    }
};
