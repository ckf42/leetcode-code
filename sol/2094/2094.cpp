struct Solution {
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int d : digits){
            ++freq[d];
        }
        vector<int> res;
        for (int d1 = 1; d1 < 10; ++d1){
            if (freq[d1] == 0){
                continue;
            }
            --freq[d1];
            for (int d2 = 0; d2 < 10; ++d2){
                if (freq[d2] == 0){
                    continue;
                }
                --freq[d2];
                for (int d3 = 0; d3 < 10; ++++d3){
                    if (freq[d3] != 0){
                        res.push_back(100 * d1 + 10 * d2 + d3);
                    }
                }
                ++freq[d2];
            }
            ++freq[d1];
        }
        return res;
    }
};
