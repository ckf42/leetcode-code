struct Solution {
    int possibleStringCount(string_view word, int k) {
        int n = word.size();
        constexpr int m = 1e9 + 7;
        vector<int> segLens = {1};
        long long allChoices = 1;
        for (int i = 1; i < n; ++i){
            if (word[i] == word[i - 1]){
                ++segLens.back();
            } else if (segLens.back() == 1){
                --k;
            } else {
                allChoices = (allChoices * segLens.back()) % m;
                segLens.push_back(1);
            }
        }
        allChoices = (allChoices * segLens.back()) % m;
        int l = segLens.size();
        if (k <= l){
            return static_cast<int>(allChoices);
        }
        vector<int> memo(k, 0), newMemo(k, 0);
        memo[0] = 1;
        int totalLen = 0;
        for (int i = 0; i < l; ++i){
            int seg = segLens[i], combLen = 0;
            totalLen += seg;
            for (; combLen <= i; ++combLen){
                newMemo[combLen] = 0;
            }
            for (; combLen < min(k, seg + 1); ++combLen){
                newMemo[combLen] = (newMemo[combLen - 1] + memo[combLen - 1]) % m;
            }
            for (; combLen < min(k, totalLen + 1); ++combLen){
                newMemo[combLen] = ((newMemo[combLen - 1] + memo[combLen - 1]) % m - memo[combLen - seg - 1] + m) % m;
            }
            for (; combLen < k; ++combLen){
                newMemo[combLen] = 0;
            }
            swap(memo, newMemo);
        }
        int total = 0;
        for (int x : memo){
            total = (total + x) % m;
        }
        return static_cast<int>((allChoices - total + m) % m);
    }
};
