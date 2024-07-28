struct Solution {
    int numberOfEmployeesWhoMetTarget(const vector<int>& hours, int target) {
        unsigned n = 0;
        for (const int &h : hours){
            if (h >= target){++n;}
        }
        return n;
    }
};
