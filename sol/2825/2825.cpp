struct Solution {
    bool canMakeSubsequence(string &str1, string &str2) {
        int n1 = str1.size(), n2 = str2.size(), ptr2 = 0;
        for (int ptr1 = 0; ptr1 < n1 && n1 - ptr1 >= n2 - ptr2; ++ptr1){
            if (str1[ptr1] == str2[ptr2]
                    || (str1[ptr1] - 'a' + 1) % 26 == str2[ptr2] - 'a'){
                ++ptr2;
            }
            if (ptr2 == n2){
                return true;
            }
        }
        return false;
    }
};
