struct Solution {
    inline double averageWaitingTime(vector<vector<int>>& customers) {
        long total = 0, cTime = 0;
        for (auto &c : customers){
            cTime = max(cTime, static_cast<long>(c[0])) + c[1];
            total += cTime - c[0];
        }
        return static_cast<double>(total) / customers.size();
    }
};
