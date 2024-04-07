struct Solution {
    bool checkValidString(string &s) {
        int depMin = 0, depMax = 0;
        for (char &c : s){
            switch (c){
                case '(':
                    ++depMin;
                    ++depMax;
                    break;
                case ')':
                    depMin = max(0, depMin - 1);
                    --depMax;
                    break;
                case '*':
                    depMin = max(0, depMin - 1);
                    ++depMax;
            }
            if (depMax < 0){
                return false;
            }
        }
        return depMin == 0;
    }
};
