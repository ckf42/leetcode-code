struct Solution {
    int equalSubstring(string &s, string &t, int maxCost) {
        int n = s.size();
        vector<int> diffs(n, 0);
        for (int i = 0; i < n; ++i){
            diffs[i] = abs(s[i] - t[i]);
        }
        int currCost = 0, j = 0, maxLen = 0;
        for (int i = 0; i < n; ++i){
            while (j < n && currCost + diffs[j] <= maxCost){
                currCost += diffs[j++];
            }
            maxLen = max(maxLen, j - i);
            currCost -= diffs[i];
        }
        return maxLen;
    }
};
