struct Solution {
    bool backspaceCompare(const string& s, const string& t) {
        string::const_reverse_iterator sptr = s.crbegin(), tptr = t.crbegin();
        size_t sBs = 0, tBs = 0;
        while (true){
            while (sptr != s.crend() && (sBs != 0 || *sptr == '#')){
                if (*sptr == '#'){
                    ++sBs;
                } else {
                    --sBs;
                }
                ++sptr;
            }
            while (tptr != t.crend() && (tBs != 0 || *tptr == '#')){
                if (*tptr == '#'){
                    ++tBs;
                } else {
                    --tBs;
                }
                ++tptr;
            }
            bool sflag = (sptr == s.crend()), tflag = (tptr == t.crend());
            if (sflag || tflag){
                return sflag && tflag;
            }
            if (*sptr != *tptr){
                return false;
            }
            ++sptr;
            ++tptr;
        }
    }
}; 
