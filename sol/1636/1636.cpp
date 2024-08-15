struct Solution {
    vector<int> frequencySort(vector<int>& nums) {
        int freq[201] = {0};
        for (int x : nums){
            ++freq[x + 100];
        }
        ranges::sort(nums, [&freq](int i, int j){
            int fi = freq[i + 100], fj = freq[j + 100];
            if (fi == fj){
                return i > j;
            } else {
                return fi < fj;
            }
        });
        return nums;
    }
};
