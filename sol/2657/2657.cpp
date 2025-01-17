struct Solution {
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> res(n, 0);
        vector<short> freq(n + 1, 0);
        for (int i = 0; i < n; ++i){
            ++freq[A[i]];
            count += (freq[A[i]] == 2);
            ++freq[B[i]];
            count += (freq[B[i]] == 2);
            res[i] = count;
        }
        return res;
    }
};
