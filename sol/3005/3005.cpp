struct Solution {
    int maxFrequencyElements(vector<int>& nums) {
        unsigned freq[101] = {0}, m = 0, count = 0;
        for (int &n : nums){
            ++freq[n];
            if (freq[n] == m){
                ++count;
            } else if (freq[n] > m){
                m = freq[n];
                count = 1;
            }
        }
        return count * m;
    }
};
