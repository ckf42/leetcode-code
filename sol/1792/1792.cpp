#include <queue>

struct Solution {
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double> ratios(n), newRatios(n);
        for (int i = 0; i < n; ++i){
            ratios[i] = static_cast<double>(classes[i][0]) / classes[i][1];
            newRatios[i] = static_cast<double>(classes[i][0] + 1) / (classes[i][1] + 1);
        }
        auto cmp = [&](int i, int j){
            return newRatios[i] - ratios[i] < newRatios[j] - ratios[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i){
            pq.push(i);
        }
        while (extraStudents-- > 0){
            int i = pq.top();
            pq.pop();
            ratios[i] = newRatios[i];
            ++classes[i][0];
            ++classes[i][1];
            newRatios[i] = static_cast<double>(classes[i][0] + 1) / (classes[i][1] + 1);
            pq.push(i);
        }
        double res = 0;
        for (double r : ratios){
            res += r;
        }
        return res / n;
    }
};
