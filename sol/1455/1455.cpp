struct Solution {
    int isPrefixOfWord(string &sentence, string &searchWord) {
        size_t ptr = 0, n = searchWord.size(), l = sentence.size();
        int wordCount = 1;
        while (ptr != string::npos){
            bool isMatch = true;
            for (int i = 0; i < n; ++i){
                if (ptr + i >= l || sentence[ptr + i] != searchWord[i]){
                    isMatch = false;
                    break;
                }
            }
            if (isMatch){
                return wordCount;
            }
            ptr = sentence.find(' ', ptr);
            if (ptr != string::npos){
                ptr = sentence.find_first_not_of(' ', ptr);
            }
            ++wordCount;
        }
        return -1;
    }
};
