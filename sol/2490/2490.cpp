struct Solution {
    bool isCircularSentence(string &sentence) {
        if (sentence.front() != sentence.back()){
            return false;
        }
        int n = sentence.size();
        for (int i = 0; i < n; ++i){
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]){
                return false;
            }
        }
        return true;
    }
};
