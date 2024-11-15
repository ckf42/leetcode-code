struct Solution {
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), prefix = 0;
        while (prefix < n - 1 && arr[prefix] <= arr[prefix + 1]){
            ++prefix;
        }
        int i = prefix, res = prefix + 1, prev = arr[n - 1] + 1;
        for (int j = n - 1; j > prefix; --j){
            if (arr[j] > prev){
                break;
            }
            prev = arr[j];
            while (i >= 0 && arr[i] > arr[j]){
                --i;
            }
            res = max(res, n + 1 - j + i);
        }
        return n - res;
    }
};
