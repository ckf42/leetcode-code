struct Solution {
    int maxDifference(string_view s, int k) {
        int n = s.size();
        vector<array<int, 5>> prefix(n + 1, {0, 0, 0, 0, 0});
        for (int i = 0; i < n; ++i){
            prefix[i + 1] = prefix[i];
            ++prefix[i + 1][s[i] - '0'];
        }
        int res = -n;
        for (int i = 0; i < 5; ++i){
            for (int j = i + 1; j < 5; ++j){
                int minDiffIJ[4] = {n * 3, n * 3, n * 3, n * 3},
                    minDiffJI[4] = {n * 3, n * 3, n * 3, n * 3};
                int l = -1;
                for (int e = k; e <= n; ++e){
                    int fa = prefix[e][i], fb = prefix[e][j], ffa, ffb;
                    while (l < e - k && fa != (ffa = prefix[l + 1][i]) && fb != (ffb = prefix[l + 1][j])){
                        ++l;
                        short state = ((ffa & 1) << 1) | (ffb & 1);
                        minDiffIJ[state] = min(minDiffIJ[state], ffa - ffb);
                        state = ((ffb & 1) << 1) | (ffa & 1);
                        minDiffJI[state] = min(minDiffJI[state], ffb - ffa);
                    }
                    if (l == -1){
                        continue;
                    }
                    res = max({
                        res,
                        fa - fb - minDiffIJ[((1 ^ (fa & 1)) << 1) | (fb & 1)],
                        fb - fa - minDiffJI[((1 ^ (fb & 1)) << 1) | (fa & 1)]
                    });
                }
            }
        }
        return res;
    }
};
