struct Solution {
    inline static bool strEq(
            string &sentence1, string &sentence2, 
            int s1, int e1, int s2, int e2) {
        if (e1 - s1 != e2 - s2){
            return false;
        }
        for (; s1 != e1 - 1; ++s1, ++s2){
            if (sentence1[s1] != sentence2[s2]){
                return false;
            }
        }
        return true;
    }
    bool areSentencesSimilar(string &sentence1, string &sentence2) {
        vector<int> idx1(1, 0), idx2(1, 0);
        int i = 0;
        while (i < sentence1.size()){
            i = sentence1.find(' ', i);
            if (i == string::npos){
                i = sentence1.size();
            }
            idx1.push_back(++i);
        }
        i = 0;
        while (i < sentence2.size()){
            i = sentence2.find(' ', i);
            if (i == string::npos){
                i = sentence2.size();
            }
            idx2.push_back(++i);
        }
        int n1 = idx1.size() - 1, n2 = idx2.size() - 1;
        if (n1 == n2){
            return sentence1 == sentence2;
        }
        int ptr1 = 0, ptr2 = 0, n = min(n1, n2);
        while (ptr1 < n
                && this->strEq(
                        sentence1, sentence2, 
                        idx1[ptr1], idx1[ptr1 + 1], idx2[ptr1], idx2[ptr1 + 1])){
            ++ptr1;
        }
        while (ptr2 < n - ptr1
                && this->strEq(
                        sentence1, sentence2, 
                        idx1[n1 - 1 - ptr2], idx1[n1 - ptr2], idx2[n2 - 1 - ptr2], idx2[n2 - ptr2])){
            ++ptr2;
        }
        return ptr1 + ptr2 == n;
    }
};
