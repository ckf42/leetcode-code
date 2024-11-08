struct Solution {
    int largestCombination(vector<int>& candidates) {
        int freq[24] = {0};
        for (int x : candidates){
            int i = 0;
            while (x != 0){
                freq[i++] += x & 1;
                x >>= 1;
            }
        }
        return *max_element(freq, freq + 24);
    }
};
