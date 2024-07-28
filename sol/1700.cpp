struct Solution {
    int countStudents(const vector<int>& students, const vector<int>& sandwiches) {
        int takers[2] = {0, 0};
        for (int c : students){
            ++takers[c];
        }
        for (int c : sandwiches){
            if (takers[c] == 0){
                return takers[0] + takers[1];
            } else {
                --takers[c];
            }
        }
        return 0;
    }
};
