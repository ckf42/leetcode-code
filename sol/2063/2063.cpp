struct Solution {
    long long countVowels(string &word) {
        long long res = 0, n = word.size();
        for (int i = 0; i < n; ++i){
            switch (word[i]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    res += (i + 1) * (n - i);
                    break;
            }
        }
        return res;
    }
};
