struct Solution {
    string reverseWords(string &s) {
        string::iterator ptr = s.begin(), pts, ptrr, ptss;
        while (true){
            pts = ptr + 1;
            while (pts != s.end() && *pts != ' '){
                ++pts;
            }
            ptrr = ptr;
            ptss = pts - 1;
            while (ptrr < ptss){
                swap(*(ptrr++), *(ptss--));
            }
            if (pts == s.end()){
                break;
            }
            ptr = pts + 1;
        }
        return s;
    }
};
