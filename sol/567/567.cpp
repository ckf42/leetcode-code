struct Solution {
    bool checkInclusion(string &s1, string &s2) {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 > l2){
            return false;
        }
        int freq[26] = {0};
        for (int i = 0; i < l1; ++i){
            --freq[s1[i] - 'a'];
            ++freq[s2[i] - 'a'];
        }
        int zCount = 0, j;
        for (int i = 0; i < 26; ++i){
            zCount += (freq[i] == 0);
        }
        if (zCount == 26){
            return true;
        }
        for (int i = l1; i < l2; ++i){
            j = s2[i] - 'a';
            ++freq[j];
            if (freq[j] == 0){
                ++zCount;
            } else if (freq[j] == 1){
                --zCount;
            }
            j = s2[i - l1] - 'a';
            --freq[j];
            if (freq[j] == 0){
                ++zCount;
            } else if (freq[j] == -1){
                --zCount;
            }
            if (zCount == 26){
                return true;
            }
        }
        return false;
    }
};
