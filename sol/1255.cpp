struct Solution {
    void backtrack(
            int idx, int currScore, int &res, int (&avail)[26],
            const int &n, const vector<array<int, 27>> &meta, const vector<int> &suff){
        if (idx == n){
            res = max(res, currScore);
            return;
        }
        if (currScore + suff[idx] < res){
            return;
        }
        bool isFeasible = true;
        for (int i = 0; i < 26; ++i){
            if (avail[i] < meta[idx][i]){
                isFeasible = false;
                break;
            }
        }
        if (isFeasible){
            for (int i = 0; i < 26; ++i){
                avail[i] -= meta[idx][i];
            }
            backtrack(idx + 1, currScore + meta[idx][26], res, avail, n, meta, suff);
            for (int i = 0; i < 26; ++i){
                avail[i] += meta[idx][i];
            }
        }
        backtrack(idx + 1, currScore, res, avail, n, meta, suff);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int avail[26] = {0};
        for (auto &l : letters){
            ++avail[l - 'a'];
        }
        vector<array<int, 27>> meta(n);
        for (int i = 0; i < n; ++i){
            for (auto &c : words[i]){
                ++meta[i][c - 'a'];
                meta[i][26] += score[c - 'a'];
            }
        }
        vector<int> suff(n, 0);
        suff[n - 1] = meta[n - 1][26];
        for (int i = n - 2; i >= 0; --i){
            suff[i] = suff[i + 1] + meta[i][26];
        }
        int res = 0;
        backtrack(0, 0, res, avail, n, meta, suff);
        return res;
    }
};
