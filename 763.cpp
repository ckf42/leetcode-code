struct Solution {
    vector<int> partitionLabels(string &s) {
        int n = s.size(), lastOccur[26] = {0}, ptr = 0;
        for (int i = 0; i < n; ++i){
            lastOccur[s[i] - 'a'] = i;
        }
        vector<int> res;
        while (ptr < n){
            int i = ptr, e = lastOccur[s[ptr] - 'a'];
            while (ptr < e){
                e = max(e, lastOccur[s[++ptr] - 'a']);
            }
            res.push_back((++ptr) - i);
        }
        return res;
    }
};
