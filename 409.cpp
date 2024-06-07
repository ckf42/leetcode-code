struct Solution {
    int longestPalindrome(string &s) {
        int freq[52] = {0};
        for (char &c : s){
            ++freq[c - (c < 'a' ? 'A' : ('a' - 26))];
        }
        int total = 0;
        bool hasOdd = false;
        for (int i = 0; i < 52; ++i){
            if (freq[i] & 1){
                hasOdd = true;
                total += freq[i] - 1;
            } else {
                total += freq[i];
            }
        }
        return total + hasOdd;
    }
};
