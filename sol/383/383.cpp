struct Solution {
    bool canConstruct(string &ransomNote, string &magazine) {
        int l = ransomNote.size();
        if (l > magazine.size()){
            return false;
        }
        int freq[26] = {0};
        for (char c : ransomNote){
            ++freq[c - 'a'];
        }
        for (char c : magazine){
            if (freq[c - 'a'] > 0){
                --freq[c - 'a'];
                --l;
            }
            if (l == 0){
                return true;
            }
        }
        return false;
    }
};
