struct Solution {
    static inline bool matchingDist(const string &s1, const string &s2){
        int n = s1.size();
        if (n != s2.size()){
            return false;
        }
        bool hasDiff = false;
        for (int i = 0; i < n; ++i){
            if (s1[i] != s2[i]){
                if (!hasDiff){
                    hasDiff = true;
                } else {
                    return false;
                }
            }
        }
        return hasDiff;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> prevIdx(n, n), seqLen(n + 1, 0);
        int maxLenIdx = n;
        for (int i = 0; i < n; ++i){
            int targetIdx = n;
            for (int j = 0; j < i; ++j){
                if (groups[j] != groups[i] && seqLen[j] > seqLen[targetIdx] && this->matchingDist(words[j], words[i])){
                    targetIdx = j;
                }
            }
            prevIdx[i] = targetIdx;
            seqLen[i] = seqLen[targetIdx] + 1;
            if (seqLen[i] > seqLen[maxLenIdx]){
                maxLenIdx = i;
            }
        }
        int l = seqLen[maxLenIdx], ptr = maxLenIdx;
        vector<string> res(l);
        for (int i = l - 1; i >= 0; --i){
            res[i] = words[ptr];
            ptr = prevIdx[ptr];
        }
        return res;
    }
};
