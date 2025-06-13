struct Solution {
    int maxDifference(string_view s) {
        array<int, 26> freq = {0};
        for (char c : s){
            ++freq[c - 'a'];
        }
        int a1 = 0, a2 = s.size();
        for (int f : freq){
            if (f & 1){
                a1 = max(a1, f);
            } else if (f != 0) {
                a2 = min(a2, f);
            }
        }
        return a1 - a2;
    }
};
