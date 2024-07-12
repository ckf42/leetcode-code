struct Solution {
    inline int minOperations(vector<string>& logs) {
        int dep = 0;
        for (auto &step : logs){
            if (step == "../"){
                dep = max(0, dep - 1);
            } else if (step != "./"){
                ++dep;
            }
        }
        return dep;
    }
};
