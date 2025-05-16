struct Solution {
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> prevIdx(n, -1), seqLen(n + 1, 1);
        seqLen[0] = 0;
        int lastOccur[2] = {-1, -1};
        for (int i = 0; i < n; ++i){
            if (lastOccur[1 - groups[i]] != -1){
                prevIdx[i] = lastOccur[1 - groups[i]];
                seqLen[i + 1] = seqLen[lastOccur[1 - groups[i]] + 1] + 1;
            }
            lastOccur[groups[i]] = i;
        }
        int gp = (seqLen[lastOccur[1] + 1] >= seqLen[lastOccur[0] + 1]) ? 1 : 0;
        int ptr = lastOccur[gp];
        vector<string> res(seqLen[ptr + 1]);
        for (int i = seqLen[ptr + 1] - 1; i >= 0; --i){
            res[i] = words[ptr];
            ptr = prevIdx[ptr];
        }
        return res;
    }
};
