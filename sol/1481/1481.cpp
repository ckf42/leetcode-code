struct Solution {
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> freq;
        int prev = 0, count = 0;
        for (int &x : arr){
            if (x == prev){
                ++count;
            } else {
                if (count != 0){
                    freq.push_back(count);
                }
                count = 1;
                prev = x;
            }
        }
        freq.push_back(count);
        sort(freq.begin(), freq.end());
        int m = freq.size(), ptr = 0;
        while (k > 0 && ptr < m && k >= freq[ptr]){
            k -= freq[ptr];
            ++ptr;
        }
        return m - ptr;
    }
};
