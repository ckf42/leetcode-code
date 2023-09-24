struct Solution {
    bool checkRecord(const string& s) {
        bool prevIsL = false;
        short consecLCount = 0, aCount = 0;
        for (auto it = s.cbegin(); it != s.cend(); ++it){
            if (*it == 'L'){
                if (prevIsL){
                    if (consecLCount == 2){
                        return false;
                    }
                    consecLCount += 1;
                } else {
                    consecLCount = 1;
                    prevIsL = true;
                }
            } else {
                if (*it == 'A'){
                    if (aCount == 1){
                        return false;
                    }
                }
                prevIsL = false;
            }
        }
        return true;
    }
};
